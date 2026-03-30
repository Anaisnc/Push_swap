
#include "push_swap.h"

static int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static void	read_and_execute_operations(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!is_empty_line(line))
		{
			if (!execute_operation(line, a, b))
			{
				free(line);
				free_both_stacks(a, b);
				write_error("Error\n");
				exit(1);
			}
		}
		free(line);
		line = get_next_line(0);
	}
}

static void	print_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && stack_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = init_stack();
	b = init_stack();
	if (!a || !b)
		error_free_exit(a, b, "Error\n");
	if (!parse_args(argc, argv, a, 1))
		error_free_exit(a, b, "Error\n");
	validate_input(a);
	assign_index(a);
	read_and_execute_operations(a, b);
	print_result(a, b);
	free_both_stacks(a, b);
	return (0);
}
