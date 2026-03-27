
#include "push_swap.h"

int	count_inversions(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	int		inversions;

	inversions = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->index > j->index)
				inversions++;
			j = j->next;
		}
		i = i->next;
	}
	return (inversions);
}

float	compute_disorder(t_stack *a)
{
	int		total_pairs;
	int		inversions;
	int		size;

	size = stack_size(a);
	if (size <= 1)
		return (0.0);
	total_pairs = (size * (size - 1)) / 2;
	inversions = count_inversions(a);
	return ((float)inversions / (float)total_pairs);
}
