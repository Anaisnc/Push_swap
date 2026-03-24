/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:55:13 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/25 12:17:38 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	int	size;
	t_node	*current_i;
	t_node	*current_j;
	int	i;

	mistakes = 0;
	size = stack_size(a);
	total_pairs = size * (size - 1) / 2;
	if (total_pairs == 0)
		return (0);
	current_i = a->top;
	i = 0;
	while (current_i && i < size - 1)
	{
		current_j = current_i->next;
		while (current_j)
		{
			if (current_i->index > current_j->index)
				mistakes++;
			current_j = current_j->next;
		}
		current_i = current_i->next;
		i++;
	}
	return ((mistakes * 100) / total_pairs);
}

void	error_exit(char *message)
{
	if (message)
		write(2, message, 6);
	else
		write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(stack);
}
