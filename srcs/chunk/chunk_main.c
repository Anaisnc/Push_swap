
#include "push_swap.h"

int	calculate_optimal_chunks(int size)
{
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (11);
	else
		return (15);
}

void	chunk_algorithm(t_stack *a, t_stack *b, int chunks, t_benchmark *stats)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	while (i < chunks)
	{
		get_chunk_range(i, chunks, stack_size(a) + stack_size(b), &min, &max);
		push_chunk_to_b(a, b, min, max, stats);
		i++;
	}
	merge_back_from_b(a, b, stats);
}
void	get_chunk_range(int id, int chunks, int size, int *min, int *max)
{
	int	chunk_size;

	chunk_size = size / chunks;
	*min = id * chunk_size;
	if (id == chunks - 1)
		*max = size;
	else
		*max = (id + 1) * chunk_size;
}

bool	is_in_chunk(int index, int min, int max)
{
	return (index >= min && index < max);
}

void	push_chunk_to_b(t_stack *a, t_stack *b, int min, int max,
		t_benchmark *stats)
{
	int	pushed;
	int	expected;

	expected = max - min;
	pushed = 0;
	while (pushed < expected && stack_size(a) > 0)
	{
		if (is_in_chunk(a->top->index, min, max))
		{
			pb(a, b, stats);
			pushed++;
			if (pushed < expected && stack_size(b) > 1)
			{
				if (a->top && is_in_chunk(a->top->index, min, max))
				{
					if (b->top->index < min + (max - min) / 2)
						rb(b, stats);
				}
			}
		}
		else
			ra(a, stats);
	}
}
