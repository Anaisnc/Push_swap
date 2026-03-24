
#include "push_swap.h"

void	medium_sort(t_stack *a, t_stack *b, t_benchmark *stats)
{
	int	size;
	int	num_chunks;

	size = stack_size(a);
	num_chunks = calculate_optimal_chunks(size);
	chunk_algorithm(a, b, num_chunks, stats);
}