/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:53:21 by ancourt           #+#    #+#             */
/*   Updated: 2026/02/23 19:39:37 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	is_valid_number(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
// conversion en entier avec atoi
int	ft_atoi(const char *str)
{
	size_t	i;
	int		result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
//split
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

static void	ft_free(char **res, size_t k)
{
	while (k > 0)
	{
		free(res[--k]);
	}
	free(res);
}

static char	*ft_dup(char const *s, size_t beg, size_t end)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * (end - beg + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (beg < end)
		word[i++] = s[beg++];
	word[i] = '\0';
	return (word);
}

static int	ft_fill(char **res, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	k;
	size_t	beg;

	i = 0;
	k = 0;
	while (s[i] && k < words)
	{
		while (s[i] && s[i] == c)
			i++;
		beg = i;
		while (s[i] && s[i] != c)
			i++;
		if (beg < i)
		{
			res[k] = ft_dup(s, beg, i);
			if (!res[k])
				return (ft_free(res, k), 0);
			k++;
		}
	}
	res[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
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
char **split_entry(char *str)
{
	char	**result;
	
	result = ft_split(str, ' '); //pour les espaces
	if(!result)
		return (NULL);
	return (result);
}
// fonction pour verifier les nombres presents plusieurs fois dans la liste
t_stack is_unique()
{
	
}
// fonction pour construire la liste


//
t_stack	parse_arguments(int ac, char **av)
{
	
	char **numbers;
	int	i;
	int	j;
	int	k;
	
	numbers = malloc(sizeof(char *) * (count_total_numbers(ac, av) + 1));
	k = 0;
	i = 1;
	while (i < ac)
	{
		if (contains_space(av[i]))
		{
			char	**split = ft_split(av[i], ' ');
			j = 0;
			while (split[j])
			{
				numbers[k++] = ft_dup(split[j]);
				j++;
			}
			free_split(split);
		}
		else
		{
			numbers[k++] = ft_dup(av[i]);
		}
		i++;
	}
	numbers[k] = NULL;
	return (numbers);
}

/*remplir la liste a a partir de l'argument utilisateur*/
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = parse_arguments(ac, av);
	if (!a)
		return (errorandquit());
	b = init_stack();
}


