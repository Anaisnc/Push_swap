/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:13:16 by ancourt           #+#    #+#             */
/*   Updated: 2026/04/01 12:13:17 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_number(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	split_len(char **split)
{
	int	j;

	j = 0;
	while (split[j])
		j++;
	return (j);
}

static int	fill_stack_from_split(t_stack *a, char **split)
{
	int		j;
	long	value;

	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
			return (0);
		value = ft_atoi(split[j]);
		if (value == LONG_MIN)
			return (0);
		stack_add_bottom(a, (int)value);
		j++;
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a, int start)
{
	char	**split;
	int		i;
	int		j;

	i = start;
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
			return (0);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		j = split_len(split);
		if (!fill_stack_from_split(a, split))
			return (free_split(split, j), 0);
		free_split(split, j);
		i++;
	}
	if (has_duplicates(a))
		return (0);
	return (1);
}

int	count_numbers(int argc, char **argv, int start)
{
	char	**split;
	int		total;
	int		i;
	int		j;

	total = 0;
	i = start;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		j = split_len(split);
		free_split(split, j);
		total += j;
		i++;
	}
	return (total);
}
