
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

void	turk_algorithm(t_stack *a, t_stack *b, t_benchmark *stats)
{
	if (stack_size(a) > 3)
		push_all_except_three(a, b, stats);
	if (stack_size(a) == 3)
		sort_three(a, stats);
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

void	lis_turk_algorithm(t_stack *a, t_stack *b, t_benchmark *stats)
{
	int	lis_len;
	int	*lis;

	lis = find_lis(a, &lis_len);
	if (lis_len < 3)
	{
		free(lis);
		turk_algorithm(a, b, stats);
		return ;
	}
	free(lis);
	push_except_lis(a, b, stats);
	if (stack_size(a) == 3 && !is_sorted(a))
		sort_three(a, stats);
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