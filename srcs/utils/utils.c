/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaiscourt <ancourt@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:55:13 by ancourt           #+#    #+#             */
/*   Updated: 2026/03/27 14:50:40 by anaiscourt       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_mistakes_from_node(t_node *node)
{
	int		mistakes;
	t_node	*current;

	mistakes = 0;
	current = node->next;
	while (current)
	{
		if (node->index > current->index)
			mistakes++;
		current = current->next;
	}
	return (mistakes);
}

int	compute_disorder(t_stack *a)
{
	int		mistakes;
	int		total_pairs;
	int		size;
	t_node	*current;

	size = stack_size(a);
	total_pairs = size * (size - 1) / 2;
	if (total_pairs == 0)
		return (0);
	mistakes = 0;
	current = a->top;
	while (current && current->next)
	{
		mistakes += count_mistakes_from_node(current);
		current = current->next;
	}
	return ((mistakes * 100) / total_pairs);
}
