/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:07:21 by ancourt           #+#    #+#             */
/*   Updated: 2026/04/01 12:07:22 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_optimal_chunks(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (11);
	else
		return (15);
}

void	chunk_algorithm(t_stack *a, t_stack *b, int chunks, t_benchmark *stats)
{
	int				i;
	t_chunk_rge		range;

	i = 0;
	while (i < chunks)
	{
		range = get_chunk_range(i, chunks, stack_size(a) + stack_size(b));
		push_chunk_to_b(a, b, range, stats);
		i++;
	}
	merge_back_from_b(a, b, stats);
}

t_chunk_rge	get_chunk_range(int id, int chunks, int size)
{
	t_chunk_rge	range;
	int			chunk_size;

	chunk_size = size / chunks;
	range.min = id * chunk_size;
	if (id == chunks - 1)
		range.max = size;
	else
		range.max = (id + 1) * chunk_size;
	return (range);
}

bool	is_in_chunk(int index, int min, int max)
{
	return (index >= min && index < max);
}

void	push_chunk_to_b(t_stack *a, t_stack *b, t_chunk_rge range,
		t_benchmark *stats)
{
	int	pushed;
	int	expected;

	expected = range.max - range.min;
	pushed = 0;
	while (pushed < expected && stack_size(a) > 0)
	{
		if (is_in_chunk(a->top->index, range.min, range.max))
		{
			pb(a, b, stats);
			pushed++;
			if (pushed < expected && stack_size(b) > 1 && a->top)
			{
				if (is_in_chunk(a->top->index, range.min, range.max)
					&& b->top->index < range.min + (range.max - range.min) / 2)
					rb(b, stats);
			}
		}
		else
			ra(a, stats);
	}
}
