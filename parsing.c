/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:53:21 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/24 21:25:57 by ancourt          ###   ########.fr       */
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

//conversion en entier avec atoi
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

//fonction pour verifier les nombres presents plusieurs fois dans la liste


//fonction pour construire la liste



//
t_stack parse_arguments(int ac, char **av)
{
	
}
//remplir la liste a a partir de l'argument utilisateur
int main(int ac, char **av)
{
	t_stack *a;
	t_stack	*b;

	if (ac < 2)
		return (0);

	a = parse_arguments(ac, av);
	if (!a)
		return ();
}

