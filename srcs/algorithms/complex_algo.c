/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:40:57 by olchacou          #+#    #+#             */
/*   Updated: 2026/04/01 11:40:58 by olchacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_sort(t_stack *a, t_stack *b, t_benchmark *stats)
{
	radix_algorithm(a, b, stats);
}
