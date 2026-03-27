
#include "push_swap.h"

void	choose_by_disorder(t_stack *a, t_stack *b, t_config *cfg)
{
	if (cfg->disorder < 0.5)
	{
		lis_turk_algorithm(a, b, &cfg->stats);
		cfg->strategy_name = "Adaptive → LIS+Turk O(n²) (low disorder)";
	}
	else
	{
		lis_turk_algorithm(a, b, &cfg->stats);
		cfg->strategy_name = "Adaptive → LIS+Turk O(n²) (high disorder)";
	}
}

void	adaptive_sort(t_stack *a, t_stack *b, t_config *cfg)
{
	int	size;

	size = stack_size(a);
	if (size == 2)
	{
		sort_two(a, &cfg->stats);
		cfg->strategy_name = "Adaptive → Hardcoded (2 elem)";
		return ;
	}
	if (size == 3)
	{
		sort_three(a, &cfg->stats);
		cfg->strategy_name = "Adaptive → Hardcoded (3 elem)";
		return ;
	}
	if (size <= 5)
	{
		sort_five(a, b, &cfg->stats);
		cfg->strategy_name = "Adaptive → Hardcoded (5 elem)";
		return ;
	}
	if (size <= 100)
	{
		lis_turk_algorithm(a, b, &cfg->stats);
		cfg->strategy_name = "Adaptive → LIS+Turk O(n²) (≤100)";
		return ;
	}
	choose_by_disorder(a, b, cfg);
}

void	sort_stack(t_stack *a, t_stack *b, t_config *cfg)
{
	int	size;

	size = stack_size(a);
	if (size == 2)
	{
		sort_two(a, &cfg->stats);
		cfg->strategy_name = "Hardcoded (2 elem)";
		return ;
	}
	if (size == 3)
	{
		sort_three(a, &cfg->stats);
		cfg->strategy_name = "Hardcoded (3 elem)";
		return ;
	}
	if (size <= 5)
	{
		sort_five(a, b, &cfg->stats);
		cfg->strategy_name = "Hardcoded (5 elem)";
		return ;
	}
	if (cfg->strategy == STRATEGY_SIMPLE)
		lis_turk_algorithm(a, b, &cfg->stats);
	else
		lis_turk_algorithm(a, b, &cfg->stats);
}
