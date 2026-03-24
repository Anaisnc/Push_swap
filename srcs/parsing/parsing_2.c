#include "push_swap.h"

static char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;
	size_t	idx;

	i = 0;
	k = 0;
	res = malloc(sizeof(char *) * 256);
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			len = i - j;
			res[k] = malloc(len + 1);
			if (!res[k])
				return (NULL);
			idx = 0;
			while (idx < len)
			{
				res[k][idx] = s[j + idx];
				idx++;
			}
			res[k][len] = '\0';
			k++;
		}
		if (k >= 255)
			break ;
	}
	res[k] = NULL;
	return (res);
}

static void	ft_free(char **res, size_t k)
{
	size_t	i;

	i = 0;
	while (i < k && res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

int	parse_args(int argc, char **argv, t_stack *a, int start)
{
	int		i;
	char	**split;
	int		j;
	long	num;

	i = start;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (1);
		j = 0;
		while (split[j])
		{
			if (!is_valid_number(split[j]))
			{
				ft_free(split, j + 1);
				return (1);
			}
			num = ft_atoi(split[j]);
			if (num > INT_MAX || num < INT_MIN)
			{
				ft_free(split, j + 1);
				return (1);
			}
			stack_add_bottom(a, (int)num);
			j++;
		}
		ft_free(split, j);
		i++;
	}
	return (0);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}
