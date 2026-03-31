
#include "push_swap.h"

static int	abs_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	min_value(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

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

t_node	*find_cheapest_node(t_stack *b)
{
	t_node	*cheapest;
	t_node	*current;
	int		min_cost;
	int		total_cost;

	cheapest = b->top;
	min_cost = 2147483647;
	current = b->top;
	while (current)
	{
		total_cost = abs_value(current->cost_a) + abs_value(current->cost_b);
		if ((current->cost_a > 0 && current->cost_b > 0)
				|| (current->cost_a < 0 && current->cost_b < 0))
			total_cost -= min_value(abs_value(current->cost_a),
					abs_value(current->cost_b));
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
