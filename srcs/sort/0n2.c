/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0n2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:22:57 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/27 17:37:32 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*selection_sort(int *array, int size)
{
	int	i;
	int	j;
	int	smaller;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		smaller = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[smaller])
				smaller = j;
				j++;
		}
		if (smaller != i)
		{
			tmp = array[i];
			array[i] = array[smaller];
			array[smaller] = tmp;
		}
		i++;
	}
	return (array);
}
#include <stdio.h>

int	main(void)
{
	int i;
	int array[6] = {7, 5, 4, 3, 2, -1};

	printf("Before: %d %d %d %d %d %d\n", array[0], array[1], array[2],
		array[3], array[4], array[5]);
	selection_sort(array, 6);
	printf("After: %d %d %d %d %d %d\n", array[0], array[1], array[2], array[3],array[4], array[5]);
	return (0);
}