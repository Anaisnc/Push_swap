
#include "push_swap.h"

void	reset_stats(t_benchmark *stats)
{
	stats->sa = 0;
	stats->sb = 0;
	stats->ss = 0;
	stats->pa = 0;
	stats->pb = 0;
	stats->ra = 0;
	stats->rb = 0;
	stats->rr = 0;
	stats->rra = 0;
	stats->rrb = 0;
	stats->rrr = 0;
	stats->total = 0;
}

void	init_benchmark(t_benchmark *stats)
{
	reset_stats(stats);
}

void	init_config(t_config *cfg)
{
	cfg->strategy = STRATEGY_ADAPTIVE;
	cfg->bench_mode = false;
	cfg->disorder = 0.0;
	cfg->strategy_name = "Adaptive";
	init_benchmark(&cfg->stats);
}

char	*get_complexity_class(t_strategy strategy)
{
	if (strategy == STRATEGY_SIMPLE)
		return ("O(n²)");
	else if (strategy == STRATEGY_MEDIUM)
		return ("O(n√n)");
	else if (strategy == STRATEGY_COMPLEX)
		return ("O(n log n)");
	else
		return ("Variable");
}
