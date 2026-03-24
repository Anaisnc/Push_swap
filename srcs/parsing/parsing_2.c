/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:48:42 by ancourt           #+#    #+#             */
/*   Updated: 2026/03/24 17:06:42 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
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
/*SPLIT*/

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*dup_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	free_split(char **res, size_t k)
{
	while (k > 0)
		free(res[--k]);
	free(res);
}

static int	fill_split(char **res, const char *s, char c, size_t words)
{
	size_t	i;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	while (s[i] && k < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			res[k] = dup_word(s, start, i);
			if (!res[k])
				return (free_split(res, k), 0);
			k++;
		}
	}
	res[k] = NULL;
	return (1);
}

static char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (!fill_split(res, s, c, words))
		return (NULL);
	return (res);
}

/* ASSIGN INDEX */

void	sort_values(int *values, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (values[j] > values[j + 1])
			{
				tmp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/* PARSE ARGS */

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
/* PUTNBR */

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}