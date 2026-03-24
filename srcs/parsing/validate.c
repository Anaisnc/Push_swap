/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:03:21 by ancourt           #+#    #+#             */
/*   Updated: 2026/03/24 17:03:22 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_int_overflow(char *str)
{
	long	num;

	num = ft_atoi(str);
	return (num > INT_MAX || num < INT_MIN);
}

void	validate_input(t_stack *a)
{
	if (has_duplicates(a))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

bool	has_duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*check;

	current = a->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}
