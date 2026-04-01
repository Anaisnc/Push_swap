/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:42:58 by olchacou          #+#    #+#             */
/*   Updated: 2026/04/01 11:42:59 by olchacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack->top)
		return (true);
	current = stack->top;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (false);
		current = current->next;
	}
	return (true);
}

bool	is_reverse_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack->top)
		return (true);
	current = stack->top;
	while (current->next)
	{
		if (current->index < current->next->index)
			return (false);
		current = current->next;
	}
	return (true);
}
