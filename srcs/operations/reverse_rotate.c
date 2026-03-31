/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:45:35 by ancourt           #+#    #+#             */
/*   Updated: 2026/03/30 21:45:39 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*before_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	before_last = NULL;
	last = stack->top;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a, t_benchmark *stats)
{
	do_reverse_rotate(a);
	write(1, "rra\n", 4);
	if (stats)
	{
		stats->rra++;
		stats->total++;
	}
}

void	rrb(t_stack *b, t_benchmark *stats)
{
	do_reverse_rotate(b);
	write(1, "rrb\n", 4);
	if (stats)
	{
		stats->rrb++;
		stats->total++;
	}
}

void	rrr(t_stack *a, t_stack *b, t_benchmark *stats)
{
	do_reverse_rotate(a);
	do_reverse_rotate(b);
	write(1, "rrr\n", 4);
	if (stats)
	{
		stats->rrr++;
		stats->total++;
	}
}
