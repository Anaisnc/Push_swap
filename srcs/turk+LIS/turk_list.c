/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaiscourt <ancourt@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:59:07 by ancourt          #+#    #+#             */
/*   Updated: 2026/03/30 12:00:00 by anaiscourt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lis	*new_lis_struct(int *lis, int lis_length)
{
	t_lis	*lis_struct;

	lis_struct = malloc(sizeof(t_lis));
	if (!lis_struct)
	{
		free(lis);
		return (NULL);
	}
	lis_struct->values = lis;
	lis_struct->length = lis_length;
	return (lis_struct);
}

t_lis	*find_lis(t_stack *a)
{
	int	*arr;
	int	*lis;
	int	*lis_len;
	int	size;
	int	lis_length;

	size = stack_size(a);
	arr = stack_to_array(a);
	if (!arr)
		return (NULL);
	lis_len = malloc(sizeof(int) * size);
	if (!lis_len)
	{
		free(arr);
		return (NULL);
	}
	calculate_lis_lengths(arr, lis_len, size);
	lis = build_lis(arr, lis_len, size, &lis_length);
	free(lis_len);
	free(arr);
	return (new_lis_struct(lis, lis_length));
}

void	push_except_lis(t_stack *a, t_stack *b, t_benchmark *stats)
{
	t_lis	*lis_struct;

	lis_struct = find_lis(a);
	if (!lis_struct)
		return ;
	push_except_lis_loop(a, b, stats, lis_struct);
	free(lis_struct->values);
	free(lis_struct);
}

int	*stack_to_array(t_stack *stack)
{
	int		*arr;
	int		size;
	int		i;
	t_node	*current;

	size = stack_size(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		arr[i] = current->index;
		current = current->next;
		i++;
	}
	return (arr);
}
