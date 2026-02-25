/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:56:25 by ancourt           #+#    #+#             */
/*   Updated: 2026/02/25 18:32:29 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

static t_node   *new_node(int value)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->index = 0;
    node->pos = 0;
    node->target_pos = 0;
    node->cost_a = 0;
    node->cost_b = 0;
    node->next = NULL;
    return (node);
}
static int push_back(t_node **stack, int value)
{
	t_node *node;
	t_node *tmp;
	
	node = new_node(value);
	if (!node)
		return (0);
	if (!*stack)
		return (*stack = node, 1);
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (1);
}

static void	error(void)
{
	write(2, "Error\n", 6);
}

static int	is_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (0);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}
static int	ft_atoi(const char *str, int *err)
{
	size_t	i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0'))
		return (error(), 0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (error(), 0);
		i++;
	}
	if (str[i] == '\0' && str[0] != '\0')
		return (result * sign);
	return (error(), 0);
}

static void	ft_free(char **res, size_t k)
{
	while (k > 0)
	{
		free(res[--k]);
	}
	free(res);
}
static size_t	ft_count_words(char const *s, char c)
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
static char	*ft_dup(char const *s, size_t start, size_t end)
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

static int	ft_fill(char **res, char const *s, char c, size_t words)
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
			res[k] = ft_dup(s, start, i);
			if (!res[k])
				return (ft_free(res, k), 0);
			k++;
		}
	}
	res[k] = NULL;
	return (1);
}

static char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (!ft_fill(res, s, c, words))
		return (NULL);
	return (res);
}
static size_t	count_numbers(int ac, char **av)
{
	char **split;
	size_t total;
	int	i;
	int	j;

	total = 0;
	i = 1;
	while (i < (size_t)ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
			j++;
		ft_free(split, j);
		total += j;
		i++;
	}
	return (total);
}
static int	fill_stack(t_node **stack, char **split, size_t *k)
{
	size_t j;
	int	value;
	int	err;
	int ret;
	
	j = 0;
	while (split[j])
	{
		err = 0;
		value = ft_atoi(split[j], &err);
		if (err == 1)
			return (0);
		ret = is_duplicate(*stack, value);
		if (ret == 1)
			return (error(), 0);
		ret = push_back(stack, value);
		if (ret == 0)
			return (0);
		(*k)++;
		j++;
	}
	return (1);
}
t_node *parse_arguments(int ac, char **av)
{
	t_node *stack;
	char **split;
	size_t	i;
	size_t	j;
	size_t	k;

	stack = NULL;
	i = 1;
	k = 0;
	while (i < (size_t)ac)
	{
		split = ft_split(av[i], ' ');
		if(!split)
			return (NULL);
		j = 0;
		while (split[j])
			j++;
		if (fill_stack(&stack, split, &k) == 0)
		{
			ft_free(split, j);
			return (NULL);
		}
		ft_free(split, j);
		i++;
	}
	return (stack);
}

static void ft_putnbr(int n)
{
    char    c;

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

int main(int ac, char **av)
{
    t_node  *stack;
    t_node  *tmp;

    if (ac < 2)
    {
        write(2, "Usage: ./push_swap [numbers]\n", 28);
        return (1);
    }
    stack = parse_arguments(ac, av);
    if (stack == NULL)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    tmp = stack;
    while (tmp)
    {
        write(1, "value: ", 7);
        ft_putnbr(tmp->value);
        write(1, "\n", 1);
        tmp = tmp->next;
    }
    return (0);
}
