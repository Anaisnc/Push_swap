#include "push_swap.h"

bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_int_overflow(char *str)
{
	long	num;

	num = ft_atoi(str);
	return (num > INT_MAX || num < INT_MIN);
}

void	validate_input(t_stack *a)
{
	if (has_duplicates(a))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

bool	has_duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*check;

	current = a->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (true);
			check = check->next;
		}
		current = current->next;
	}
	return (false);
}
