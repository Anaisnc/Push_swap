/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:45:35 by ancourt           #+#    #+#             */
/*   Updated: 2026/04/01 16:41:02 by olchacou         ###   ########.fr       */
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
	op_print_config(stats, "rra\n", 4);
	if (stats)
	{
		stats->rra++;
		stats->total++;
	}
}

void	rrb(t_stack *b, t_benchmark *stats)
{
	do_reverse_rotate(b);
	op_print_config(stats, "rrb\n", 4);
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
	op_print_config(stats, "rrr\n", 4);
	if (stats)
	{
		stats->rrr++;
		stats->total++;
	}
}
