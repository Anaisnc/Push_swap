
#include "push_swap.h"

void	assign_current_position(t_stack *stack)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}

int	find_target_in_a(t_stack *a, int b_index)
{
	int		target_pos;
	int		target_index;
	t_node	*current;
	int		pos;

	target_pos = -1;
	target_index = 2147483647;
	current = a->top;
	pos = 0;
	while (current)
	{
		if (current->index > b_index && current->index < target_index)
		{
			target_index = current->index;
			target_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (target_pos == -1)
		target_pos = find_position_of_index(a, find_min_index(a));
	return (target_pos);
}

void	assign_target_position(t_stack *a, t_stack *b)
{
	t_node	*b_node;

	b_node = b->top;
	while (b_node)
	{
		b_node->target_pos = find_target_in_a(a, b_node->index);
		b_node = b_node->next;
	}
}