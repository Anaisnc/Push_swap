/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:41:04 by olchacou          #+#    #+#             */
/*   Updated: 2026/04/01 11:41:05 by olchacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_sort(t_stack *a, t_stack *b, t_benchmark *stats)
{
	int	size;
	int	num_chunks;

	size = stack_size(a);
	num_chunks = calculate_optimal_chunks(size);
	chunk_algorithm(a, b, num_chunks, stats);
}
