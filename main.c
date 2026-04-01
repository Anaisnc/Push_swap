/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:38:32 by olchacou          #+#    #+#             */
/*   Updated: 2026/04/01 16:54:10 by olchacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_sort(t_stack *a, t_stack *b, t_config *config)
{
	if (config->strategy == STRATEGY_ADAPTIVE)
		adaptive_sort(a, b, config);
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
	else
		print_benchmark(config);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	config;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		return (write(2, "Error\n", 6), 1);
	config.strategy = STRATEGY_ADAPTIVE;
	config.bench_mode = false;
	config.stats = (t_benchmark){0};
	config.stats.print_ops = true;
	if (!parse_args(argc, argv, a, parse_all_flags(argc, argv, &config)))
		error_free_exit(a, b, "Error\n");
	set_strategy_name(&config);
	validate_input(a);
	assign_index(a);
	config.disorder = (float)compute_disorder(a) / 100.0;
	if (!is_sorted(a))
		run_sort(a, b, &config);
	print_stats(&config);
	free_stack(a);
	return (free_stack(b), 0);
}
