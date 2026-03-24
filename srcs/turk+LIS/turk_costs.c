
#include "push_swap.h"

int	calculate_rotation_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return ((size - pos) * -1);
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_node	*b_node;
	int		size_a;
	int		size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	b_node = b->top;
	while (b_node)
	{
		b_node->cost_b = calculate_rotation_cost(b_node->pos, size_b);
		b_node->cost_a = calculate_rotation_cost(b_node->target_pos, size_a);
		b_node = b_node->next;
	}
}