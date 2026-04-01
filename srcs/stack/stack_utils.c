/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:45:09 by olchacou          #+#    #+#             */
/*   Updated: 2026/04/01 11:45:10 by olchacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	return (stack->size);
}

t_node	*get_node_at_pos(t_stack *stack, int pos)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current && i < pos)
	{
		current = current->next;
		i++;
	}
	return (current);
}

t_node	*stack_get_bottom(t_stack *stack)
{
	t_node	*current;

	if (!stack->top)
		return (NULL);
	current = stack->top;
	while (current->next)
		current = current->next;
	return (current);
}
