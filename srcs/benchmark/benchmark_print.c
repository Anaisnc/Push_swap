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


static void	print_op_line(char *name1, int v1, char *name2, int v2)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd(name1, 2);
	ft_putnbr_fd(v1, 2);
	ft_putstr_fd(", ", 2);
	ft_putstr_fd(name2, 2);
	ft_putnbr_fd(v2, 2);
	ft_putstr_fd("\n", 2);
}

void	print_operations_count(t_benchmark *stats)
{
	print_op_line("sa: ", stats->sa, "sb: ", stats->sb);
	ft_putstr_fd("[bench] ss: ", 2);
	ft_putnbr_fd(stats->ss, 2);
	ft_putstr_fd("\n", 2);
	print_op_line("pa: ", stats->pa, "pb: ", stats->pb);
	print_op_line("ra: ", stats->ra, "rb: ", stats->rb);
	ft_putstr_fd("[bench] rr: ", 2);
	ft_putnbr_fd(stats->rr, 2);
	ft_putstr_fd("\n", 2);
	print_op_line("rra: ", stats->rra, "rrb: ", stats->rrb);
	ft_putstr_fd("[bench] rrr: ", 2);
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
