#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_config	config;
	int		start_idx;

	if (argc < 2)
	{
		write(2, "Usage: ./push_swap [numbers]\n", 28);
		return (1);
	}

	// Initialize stacks
	a = init_stack();
	b = init_stack();
	if (!a || !b)
	{
		write(2, "Error: Memory allocation failed\n", 32);
		return (1);
	}

	// Initialize config
	config.strategy = STRATEGY_ADAPTIVE;
	config.bench_mode = false;
	config.stats = (t_benchmark){0};

	// Parse flags
	start_idx = parse_all_flags(argc, argv, &config);

	// Parse numbers
	if (parse_args(argc, argv, a, start_idx) != 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	// Validate input
	validate_input(a);

	// Assign indices
	assign_index(a);

	// Choose algorithm based on size
	if (stack_size(a) <= 3)
		sort_three(a, &config.stats);
	else if (stack_size(a) <= 5)
		sort_five(a, b, &config.stats);
	else
		lis_turk_algorithm(a, b, &config.stats);

	// Print stats if bench mode
	if (config.bench_mode)
	{
		write(1, "Total operations: ", 18);
		ft_putnbr(config.stats.total);
		write(1, "\n", 1);
	}

	return (0);
}
