/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:00:50 by olchacou          #+#    #+#             */
/*   Updated: 2026/04/01 16:41:02 by olchacou         ###   ########.fr       */
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
	op_print_config(stats, "ra\n", 3);
	if (stats)
	{
		stats->ra++;
		stats->total++;
	}
}

void	rb(t_stack *b, t_benchmark *stats)
{
	do_rotate(b);
	op_print_config(stats, "rb\n", 3);
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
	op_print_config(stats, "rr\n", 3);
	if (stats)
	{
		stats->rr++;
		stats->total++;
	}
}
