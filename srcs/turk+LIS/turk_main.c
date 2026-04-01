/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:43:34 by olchacou          #+#    #+#             */
/*   Updated: 2026/04/01 11:54:55 by olchacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_except_three(t_stack *a, t_stack *b, t_benchmark *stats)
{
	int	size;
	int	push_count;

	size = stack_size(a);
	push_count = 0;
	while (size - push_count > 3)
	{
		pb(a, b, stats);
		push_count++;
	}
}

void	execute_moves_and_finalize(t_stack *a, t_stack *b, t_benchmark *stats)
{
	while (stack_size(b) > 0)
	{
		assign_current_position(a);
		assign_current_position(b);
		assign_target_position(a, b);
		calculate_cost(a, b);
		execute_cheapest_move(a, b, stats);
	}
	if (!is_sorted(a))
		final_rotate_to_min(a, stats);
}

void	turk_algorithm(t_stack *a, t_stack *b, t_benchmark *stats)
{
	if (stack_size(a) > 3)
		push_all_except_three(a, b, stats);
	if (stack_size(a) == 3)
		sort_three(a, stats);
	execute_moves_and_finalize(a, b, stats);
}

void	lis_turk_algorithm(t_stack *a, t_stack *b, t_benchmark *stats)
{
	t_lis	*lis_struct;

	lis_struct = find_lis(a);
	if (!lis_struct || lis_struct->length < 3)
	{
		if (lis_struct)
		{
			free(lis_struct->values);
			free(lis_struct);
		}
		turk_algorithm(a, b, stats);
		return ;
	}
	free(lis_struct->values);
	free(lis_struct);
	push_except_lis(a, b, stats);
	if (stack_size(a) == 3 && !is_sorted(a))
		sort_three(a, stats);
	execute_moves_and_finalize(a, b, stats);
}
