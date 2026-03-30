
#include "push_swap.h"

int	ft_strcmp_checker(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	do_ss_silent(t_stack *a, t_stack *b)
{
	do_swap(a);
	do_swap(b);
}

void	do_ra_silent(t_stack *a)
{
	do_rotate(a);
}

void	do_rb_silent(t_stack *b)
{
	do_rotate(b);
}

void	do_rr_silent(t_stack *a, t_stack *b)
{
	do_rotate(a);
	do_rotate(b);
}
