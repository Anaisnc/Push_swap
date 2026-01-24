/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:55:13 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/24 21:27:14 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ajouter un cas pour les pourcentages dans printf pour gérer le retour de compute_disorder. float + calcul * 100.
int	compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;
	
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size_a - 1)
	{
		j = i + 1;
		while (j < size_a - 1)
		{
			total_pairs++;
			if (a[i] > a[j])
				mistakes++;
		}
	}
	return (mistakes / total_pairs);
}

void	error_exit(void)
{
	
}

void	free_stack(t_stack *stack)
{
	
}