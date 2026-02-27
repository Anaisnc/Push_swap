
#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->pos = 0;
	node->target_pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

void	stack_add_bottom(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*current;

	node = create_node(value);
	if (!node)
		return ;
	if (!stack->top)
		stack->top = node;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = node;
	}
	stack->size++;
}
