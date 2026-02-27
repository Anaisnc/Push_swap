/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:00:40 by olchacou          #+#    #+#             */
/*   Updated: 2026/02/25 18:01:59 by olchacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	do_push(t_stack *src, t_stack *dst)
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
		stats->pa++;
}

void	pb(t_stack *a, t_stack *b, t_benchmark *stats)
{
	do_push(a, b);
	write(1, "pb\n", 3);
	if (stats)
		stats->pb++;
}
