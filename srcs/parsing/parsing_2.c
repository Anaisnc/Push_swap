/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 17:56:25 by ancourt           #+#    #+#             */
/*   Updated: 2026/02/24 18:02:51 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

int	ft_atoi(const char *str)
{
	size_t	i;
	long		result;
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
		return (12); //error
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (12);
		i++;
	}
	if (str[i] == '\0' && str[0] != '\0')
		return (result * sign);
	return (12); // error
}

#include <stdio.h>

int main(void)
{
    char *tests[] = {
        "42",
        "-42",
        "+42",
        "0",
        "-0",
        "+0",
        "abc",
        "14abc",
        "",
        "+ 2",
        "-- 3",
        "2147483648",
        "-2147483649",
        "  42",
        "4 2",
    };
    int i = 0;

    while (i < 16)
    {
        if (tests[i] == NULL)
            printf("%-20s -> %d\n", "NULL", ft_atoi(tests[i]));
        else
            printf("%-20s -> %d\n", tests[i], ft_atoi(tests[i]));
        i++;
    }
    return (0);
}