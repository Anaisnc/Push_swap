/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <your_login@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/02/05 12:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
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

void	print_operations_count(t_benchmark *stats)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(stats->sa, 2);
	ft_putstr_fd(", sb: ", 2);
	ft_putnbr_fd(stats->sb, 2);
	ft_putstr_fd(", ss: ", 2);
	ft_putnbr_fd(stats->ss, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] pa: ", 2);
	ft_putnbr_fd(stats->pa, 2);
	ft_putstr_fd(", pb: ", 2);
	ft_putnbr_fd(stats->pb, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(stats->ra, 2);
	ft_putstr_fd(", rb: ", 2);
	ft_putnbr_fd(stats->rb, 2);
	ft_putstr_fd(", rr: ", 2);
	ft_putnbr_fd(stats->rr, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] rra: ", 2);
	ft_putnbr_fd(stats->rra, 2);
	ft_putstr_fd(", rrb: ", 2);
	ft_putnbr_fd(stats->rrb, 2);
	ft_putstr_fd(", rrr: ", 2);
	ft_putnbr_fd(stats->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_benchmark(t_config *cfg)
{
	ft_putstr_fd("[bench] Disorder: ", 2);
	ft_putnbr_fd((int)(cfg->disorder * 100), 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd((int)((cfg->disorder * 10000)) % 100, 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] Strategy: ", 2);
	ft_putstr_fd(cfg->strategy_name, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(get_complexity_class(cfg->strategy), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] Total operations: ", 2);
	ft_putnbr_fd(cfg->stats.total, 2);
	ft_putstr_fd("\n", 2);
	print_operations_count(&cfg->stats);
}
