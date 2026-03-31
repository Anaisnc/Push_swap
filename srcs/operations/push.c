/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:00:40 by olchacou          #+#    #+#             */
/*   Updated: 2026/03/30 21:47:37 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(t_stack *src, t_stack *dst)
{
	t_node	*tmp;

	if (!src || !src->top)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	src->size--;
	tmp->next = dst->top;
	dst->top = tmp;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b, t_benchmark *stats)
{
	do_push(b, a);
	write(1, "pa\n", 3);
	if (stats)
	{
		stats->pa++;
		stats->total++;
	}
}

void	pb(t_stack *a, t_stack *b, t_benchmark *stats)
{
	do_push(a, b);
	write(1, "pb\n", 3);
	if (stats)
	{
		stats->pb++;
		stats->total++;
	}
}
