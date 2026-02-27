/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:00:56 by olchacou          #+#    #+#             */
/*   Updated: 2026/02/25 18:03:02 by olchacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	do_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	sa(t_stack *a, t_benchmark *stats)
{
	do_swap(a);
	write(1, "sa\n", 3);
	if (stats)
		stats->sa++;
}

void	sb(t_stack *b, t_benchmark *stats)
{
	do_swap(b);
	write(1, "sb\n", 3);
	if (stats)
		stats->sb++;
}

void	ss(t_stack *a, t_stack *b, t_benchmark *stats)
{
	do_swap(a);
	do_swap(b);
	write(1, "ss\n", 3);
	if (stats)
		stats->ss++;
}
