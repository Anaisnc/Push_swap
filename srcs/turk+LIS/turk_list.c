
#include "push_swap.h"

int	*stack_to_array(t_stack *stack)
{
	int		*arr;
	int		size;
	int		i;
	t_node	*current;

	size = stack_size(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		arr[i] = current->index;
		current = current->next;
		i++;
	}
	return (arr);
}

bool	is_in_lis(int index, int *lis, int lis_len)
{
	int	i;

	i = 0;
	while (i < lis_len)
	{
		if (lis[i] == index)
			return (true);
		i++;
	}
	return (false);
}

static void	calculate_lis_lengths(int *arr, int *lis_len, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		lis_len[i] = 1;
		i++;
	}
	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && lis_len[j] + 1 > lis_len[i])
				lis_len[i] = lis_len[j] + 1;
			j++;
		}
		i++;
	}
}

static int	find_max_lis_index(int *lis_len, int size, int *max_len)
{
	int	i;
	int	max_idx;

	*max_len = 0;
	max_idx = 0;
	i = 0;
	while (i < size)
	{
		if (lis_len[i] > *max_len)
		{
			*max_len = lis_len[i];
			max_idx = i;
		}
		i++;
	}
	return (max_idx);
}

static void	reconstruct_lis(int *arr, int *lis_len, int *lis, int max_idx)
{
	int	i;
	int	lis_idx;

	lis_idx = lis_len[max_idx] - 1;
	i = max_idx;
	while (i >= 0 && lis_idx >= 0)
	{
		if (lis_len[i] == lis_idx + 1)
		{
			lis[lis_idx] = arr[i];
			lis_idx--;
		}
		i--;
	}
}

int	*find_lis(t_stack *a, int *lis_length)
{
	int	*arr;
	int	*lis;
	int	*lis_len;
	int	size;
	int	max_len;
	int	max_idx;

	size = stack_size(a);
	arr = stack_to_array(a);
	if (!arr)
		return (NULL);
	lis_len = malloc(sizeof(int) * size);
	lis = malloc(sizeof(int) * size);
	if (!lis_len || !lis)
	{
		free(arr);
		free(lis_len);
		free(lis);
		return (NULL);
	}
	calculate_lis_lengths(arr, lis_len, size);
	max_idx = find_max_lis_index(lis_len, size, &max_len);
	reconstruct_lis(arr, lis_len, lis, max_idx);
	*lis_length = max_len;
	free(lis_len);
	free(arr);
	return (lis);
}

void	push_except_lis(t_stack *a, t_stack *b, t_benchmark *stats)
{
	int	*lis;
	int	lis_len;
	int	size;
	int	pushed;
	int	rotations;

	lis = find_lis(a, &lis_len);
	if (!lis)
		return ;
	size = stack_size(a);
	pushed = 0;
	rotations = 0;
	while (pushed < size - lis_len)
	{
		if (!is_in_lis(a->top->index, lis, lis_len))
		{
			pb(a, b, stats);
			pushed++;
			rotations = 0;
		}
		else
		{
			ra(a, stats);
			rotations++;
		}
		if (rotations > size * 2)
			break ;
	}
	free(lis);
}