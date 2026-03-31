
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

static int	is_command(char *op, char *cmd)
{
	int	op_len;
	int	cmd_len;

	op_len = 0;
	while (op[op_len] && op[op_len] != '\n')
		op_len++;
	cmd_len = 0;
	while (cmd[cmd_len])
		cmd_len++;
	if (op_len != cmd_len)
		return (0);
	while (cmd_len-- > 0)
	{
		if (op[cmd_len] != cmd[cmd_len])
			return (0);
	}
	return (1);
}


