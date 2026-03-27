/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaiscourt <ancourt@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:03:07 by ancourt           #+#    #+#             */
/*   Updated: 2026/03/27 14:57:36 by anaiscourt       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

static long	ft_atoi_digits(const char *str, size_t i, int sign)
{
	long	result;

	result = 0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (LONG_MIN);
		i++;
	}
	if (str[i] != '\0')
		return (LONG_MIN);
	return (result * sign);
}

long	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (LONG_MIN);
	return (ft_atoi_digits(str, i, sign));
}

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
