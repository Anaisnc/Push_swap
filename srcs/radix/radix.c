
#include "push_swap.h"

int	get_max_bits(int max_num)
{
	int	bits;
	int	n;

	bits = 0;
	n = max_num;
	while (n > 0)
	{
		bits++;
		n >>= 1;
	}
	return (bits);
}

int	get_bit(int num, int bit_pos)
{
	return ((num >> bit_pos) & 1);
}

void	radix_algorithm(t_stack *a, t_stack *b, t_benchmark *stats)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	max_bits = get_max_bits(stack_size(a));
	bit = 0;
	while (bit < max_bits)
	{
		size = stack_size(a);
		i = 0;
		while (i < size)
		{
			if (get_bit(a->top->index, bit) == 0)
				pb(a, b, stats);
			else
				ra(a, stats);
			i++;
		}
		while (stack_size(b) > 0)
			pa(a, b, stats);
		bit++;
	}
}