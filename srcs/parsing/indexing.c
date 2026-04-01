/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:42:35 by olchacou          #+#    #+#             */
/*   Updated: 2026/04/01 11:42:36 by olchacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*create_sorted_array(t_stack *a)
{
	int		*arr;
	int		size;
	int		i;
	t_node	*current;

	size = stack_size(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	current = a->top;
	i = 0;
	while (current)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	sort_array(arr, size);
	return (arr);
}

int	find_value_index(t_stack *a, int value)
{
	int		*sorted;
	int		size;
	int		i;
	int		index;

	sorted = create_sorted_array(a);
	if (!sorted)
		return (-1);
	size = stack_size(a);
	i = 0;
	index = -1;
	while (i < size)
	{
		if (sorted[i] == value)
		{
			index = i;
			break ;
		}
		i++;
	}
	free(sorted);
	return (index);
}

void	assign_index(t_stack *a)
{
	t_node	*current;

	current = a->top;
	while (current)
	{
		current->index = find_value_index(a, current->value);
		current = current->next;
	}
}
