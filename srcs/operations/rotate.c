/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:00:50 by olchacou          #+#    #+#             */
/*   Updated: 2026/03/30 21:47:30 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack *a, t_benchmark *stats)
{
	do_rotate(a);
	write(1, "ra\n", 3);
	if (stats)
	{
		stats->ra++;
		stats->total++;
	}
}

void	rb(t_stack *b, t_benchmark *stats)
{
	do_rotate(b);
	write(1, "rb\n", 3);
	if (stats)
	{
		stats->rb++;
		stats->total++;
	}
}

void	rr(t_stack *a, t_stack *b, t_benchmark *stats)
{
	do_rotate(a);
	do_rotate(b);
	write(1, "rr\n", 3);
	if (stats)
	{
		stats->rr++;
		stats->total++;
	}
}
