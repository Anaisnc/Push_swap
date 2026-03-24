#include "push_swap.h"

static void	run_sort(t_stack *a, t_stack *b, t_config *config)
{
	if (stack_size(a) == 2)
    	sort_two(a, &config->stats);
	else if (stack_size(a) <= 3)
		sort_three(a, &config->stats);
	else if (stack_size(a) <= 5)
		sort_five(a, b, &config->stats);
	else
		lis_turk_algorithm(a, b, &config->stats);
}

static void	print_stats(t_config *config)
{
	if (!config->bench_mode)
		return ;
	write(1, "Total operations: ", 18);
	ft_putnbr(config->stats.total);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	config;

	if (argc < 2)
		return (write(2, "Usage: ./push_swap [numbers]\n", 28), 1);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (write(2, "Error\n", 6), 1);
	config.strategy = STRATEGY_ADAPTIVE;
	config.bench_mode = false;
	config.stats = (t_benchmark){0};
	if (!parse_args(argc, argv, a, parse_all_flags(argc, argv, &config)))
		error_free_exit(a, b, "Error\n");
	validate_input(a);
	assign_index(a);
	if (!is_sorted(a))
		run_sort(a, b, &config);
	print_stats(&config);
	free_stack(a);
	free_stack(b);
	return (0);
}