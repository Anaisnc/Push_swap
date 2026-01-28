/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:27:11 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/28 17:35:37 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *stack_a)
{
	int	tmp;

	if (stack_a == NULL || stack_a->next == NULL)
		return ;
	tmp = stack_a->value;
	stack_a->value = stack_a->next->value;
	stack_a->next->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_node *stack_b)
{
	int tmp;

	if (stack_b == NULL || stack_b->next == NULL)
		return ;
	tmp = stack_b->value;
	stack_b->value = stack_b->next->value;
	stack_b->next->value = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_node *stack_a, t_node *stack_b)
{
		sa(stack_a);
		sb(stack_b);
}

void	pa(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp;
	
	if (stack_b == NULL)
		return ;

	tmp = stack_b;
	stack_b = stack_b->next;
	tmp->next = stack_a;
	stack_a = tmp;
	write(1, "pa\n", 3);
}

void	pb(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp;
	
	if (stack_a == NULL)
		return ;

	tmp = stack_a;
	stack_a = stack_a->next;
	tmp->next = stack_b;
	stack_b = tmp;
	write(1, "pb\n", 3);
}

void	ra(t_node *stack_a)
{}
void	rb(t_node *stack_b)
{}
void	rr(t_node *stack_a, t_node *stack_b)
{}
void	rra(t_node *stack_a)
{}
void	rrb(t_node *stack_b)
{}

void	rrr(t_node *stack_a, t_node *stack_b)
{}