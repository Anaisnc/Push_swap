
#include "push_swap.h"

typedef struct s_move_costs
{
	int	a;
	int	b;
} 	t_move_costs;

static void	do_rotations(t_stack *a, t_stack *b, t_move_costs *costs,
		t_benchmark *stats)
{
	while (costs->a > 0 && costs->b > 0)
	{
		rr(a, b, stats);
		costs->a--;
		costs->b--;
	}
	while (costs->a < 0 && costs->b < 0)
	{
		rrr(a, b, stats);
		costs->a++;
		costs->b++;
	}
}

void	rotate_stack_a(t_stack *a, int *cost, t_benchmark *stats)
{
	while (*cost > 0)
	{
		ra(a, stats);
		(*cost)--;
	}
	while (*cost < 0)
	{
		rra(a, stats);
		(*cost)++;
	}
}

void	rotate_stack_b(t_stack *b, int *cost, t_benchmark *stats)
{
	while (*cost > 0)
	{
		rb(b, stats);
		(*cost)--;
	}
	while (*cost < 0)
	{
		rrb(b, stats);
		(*cost)++;
	}
}

void	execute_cheapest_move(t_stack *a, t_stack *b, t_benchmark *stats)
{
	t_node			*cheapest;
	t_move_costs	costs;

	cheapest = find_cheapest_node(b);
	costs.a = cheapest->cost_a;
	costs.b = cheapest->cost_b;
	do_rotations(a, b, &costs, stats);
	rotate_stack_a(a, &costs.a, stats);
	rotate_stack_b(b, &costs.b, stats);
	pa(a, b, stats);
}

void	final_rotate_to_min(t_stack *a, t_benchmark *stats)
{
	int	min_index;
	int	min_pos;
	int	size;

	min_index = find_min_index(a);
	min_pos = find_position_of_index(a, min_index);
	size = stack_size(a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a, stats);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a, stats);
			min_pos++;
		}
	}
}
