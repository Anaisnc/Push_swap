/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:16:30 by ancourt           #+#    #+#             */
/*   Updated: 2026/03/30 22:24:13 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	calculate_lis_lengths(int *arr, int *lis_len, int size)
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

int	get_lis_max_index(int *lis_len, int size)
{
	int	max_idx;
	int	i;

	max_idx = 0;
	i = 1;
	while (i < size)
	{
		if (lis_len[i] > lis_len[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

int	*build_lis(int *arr, int *lis_len, int size, int *lis_length)
{
	int	max_idx;
	int	len;
	int	i;
	int	*lis;

	if (size <= 0)
	{
		*lis_length = 0;
		return (NULL);
	}
	max_idx = get_lis_max_index(lis_len, size);
	len = lis_len[max_idx];
	*lis_length = len;
	lis = malloc(sizeof(int) * len);
	if (!lis)
		return (NULL);
	i = max_idx;
	while (i >= 0 && len > 0)
	{
		if (lis_len[i] == len)
			lis[--len] = arr[i];
		i--;
	}
	return (lis);
}

void	push_except_lis_loop(t_stack *a, t_stack *b, t_benchmark *stats,
				t_lis *lis_struct)
{
	int	pushed;
	int	rotations;
	int	size;

	size = stack_size(a);
	pushed = 0;
	rotations = 0;
	while (pushed < size - lis_struct->length)
	{
		if (!is_in_lis(a->top->index, lis_struct->values, lis_struct->length))
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
}
