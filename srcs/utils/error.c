/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:06:48 by ancourt           #+#    #+#             */
/*   Updated: 2026/03/24 17:06:49 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ERROR & EXIT */

void	write_error(char *message)
{
	int	i;

	i = 0;
	while (message[i])
		i++;
	write(2, message, i);
}

void	error_exit(char *message)
{
	write_error(message);
	exit(1);
}

void	error_free_exit(t_stack *a, t_stack *b, char *message)
{
	free_stack(a);
	free_stack(b);
	write_error(message);
	exit(1);
}