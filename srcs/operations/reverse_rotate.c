
#include "push_swap.h"

static void	do_reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*before_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	before_last = NULL;
	last = stack->top;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a, t_benchmark *stats)
{
	do_reverse_rotate(a);
	write(1, "rra\n", 4);
	if (stats)
		stats->rra++;
}

void	rrb(t_stack *b, t_benchmark *stats)
{
	do_reverse_rotate(b);
	write(1, "rrb\n", 4);
	if (stats)
		stats->rrb++;
}

void	rrr(t_stack *a, t_stack *b, t_benchmark *stats)
{
	do_reverse_rotate(a);
	do_reverse_rotate(b);
	write(1, "rrr\n", 4);
	if (stats)
		stats->rrr++;
}