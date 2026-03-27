
#include "push_swap.h"

int	find_max_position(t_stack *b)
{
	t_node	*current;
	int		max_index;
	int		max_pos;
	int		pos;

	current = b->top;
	max_index = current->index;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

void	optimal_rotation_b(t_stack *b, int pos, t_benchmark *stats)
{
	int	size;

	size = stack_size(b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b, stats);
	}
	else
	{
		while (pos++ < size)
			rrb(b, stats);
	}
}

void	merge_back_from_b(t_stack *a, t_stack *b, t_benchmark *stats)
{
	int	max_pos;

	while (stack_size(b) > 0)
	{
		max_pos = find_max_position(b);
		optimal_rotation_b(b, max_pos, stats);
		pa(a, b, stats);
	}
}
