
#include "push_swap.h"

int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min;

	current = stack->top;
	min = current->index;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max;

	current = stack->top;
	max = current->index;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

int	find_position_of_index(t_stack *stack, int index)
{
	t_node	*current;
	int		pos;

	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current->index == index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}
