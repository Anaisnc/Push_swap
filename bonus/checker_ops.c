
#include "push_swap.h"


void	do_pb_silent(t_stack *a, t_stack *b)
{
	do_push(a, b);
}

void	do_sa_silent(t_stack *a)
{
	do_swap(a);
}

void	do_sb_silent(t_stack *b)
{
	do_swap(b);
}

static int	execute_operation_part2(char *op, t_stack *a, t_stack *b)
{
	if (ft_strcmp_checker(op, "rra\n") == 0)
		do_reverse_rotate(a);
	else if (ft_strcmp_checker(op, "rrb\n") == 0)
		do_reverse_rotate(b);
	else if (ft_strcmp_checker(op, "rrr\n") == 0)
	{
		do_reverse_rotate(a);
		do_reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}

int	execute_operation(char *op, t_stack *a, t_stack *b)
{
	if (ft_strcmp_checker(op, "sa\n") == 0)
		do_sa_silent(a);
	else if (ft_strcmp_checker(op, "sb\n") == 0)
		do_sb_silent(b);
	else if (ft_strcmp_checker(op, "ss\n") == 0)
		do_ss_silent(a, b);
	else if (ft_strcmp_checker(op, "pa\n") == 0)
		do_pa_silent(a, b);
	else if (ft_strcmp_checker(op, "pb\n") == 0)
		do_pb_silent(a, b);
	else if (ft_strcmp_checker(op, "ra\n") == 0)
		do_ra_silent(a);
	else if (ft_strcmp_checker(op, "rb\n") == 0)
		do_rb_silent(b);
	else if (ft_strcmp_checker(op, "rr\n") == 0)
		do_rr_silent(a, b);
	else
		return (execute_operation_part2(op, a, b));
	return (1);
}
