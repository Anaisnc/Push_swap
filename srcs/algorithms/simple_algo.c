

#include "push_swap.h"

void	sort_two(t_stack *a, t_benchmark *stats)
{
	if (a->top->index > a->top->next->index)
		sa(a, stats);
}

void	sort_three(t_stack *a, t_benchmark *stats)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && second < third && first < third)
		sa(a, stats);
	else if (first > second && second > third)
	{
		sa(a, stats);
		rra(a, stats);
	}
	else if (first > second && second < third && first > third)
		ra(a, stats);
	else if (first < second && second > third && first < third)
	{
		sa(a, stats);
		ra(a, stats);
	}
	else if (first < second && second > third && first > third)
		rra(a, stats);
}

static void	push_min_to_b(t_stack *a, t_stack *b, t_benchmark *stats)
{
	int	min_pos;
	int	size;

	min_pos = find_position_of_index(a, find_min_index(a));
	size = stack_size(a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, stats);
	}
	else
	{
		while (min_pos++ < size)
			rra(a, stats);
	}
	pb(a, b, stats);
}

void	sort_five(t_stack *a, t_stack *b, t_benchmark *stats)
{
	while (stack_size(a) > 3)
		push_min_to_b(a, b, stats);
	sort_three(a, stats);
	while (stack_size(b) > 0)
		pa(a, b, stats);
}