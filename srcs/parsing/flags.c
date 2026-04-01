/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olchacou <olchacou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:57:30 by ancourt           #+#    #+#             */
/*   Updated: 2026/04/01 16:29:47 by olchacou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

t_strategy	parse_strategy_flag(char *flag)
{
	if (ft_strcmp(flag, "--simple") == 0)
		return (STRATEGY_SIMPLE);
	if (ft_strcmp(flag, "--medium") == 0)
		return (STRATEGY_MEDIUM);
	if (ft_strcmp(flag, "--complex") == 0)
		return (STRATEGY_COMPLEX);
	if (ft_strcmp(flag, "--adaptive") == 0)
		return (STRATEGY_ADAPTIVE);
	return (STRATEGY_ADAPTIVE);
}

bool	parse_bench_flag(char *flag)
{
	if (ft_strcmp(flag, "--bench") == 0)
		return (true);
	return (false);
}

int	parse_all_flags(int argc, char **argv, t_config *cfg)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (parse_bench_flag(argv[i]))
				cfg->bench_mode = true;
			else
				cfg->strategy = parse_strategy_flag(argv[i]);
			i++;
		}
		else
			break ;
	}
	return (i);
}
