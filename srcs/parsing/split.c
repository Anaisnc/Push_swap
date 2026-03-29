#include "push_swap.h"

size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	*dup_word(const char *s, size_t start, size_t end)
{
	char	*word;
	size_t	i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

void	free_split(char **res, size_t k)
{
	while (k > 0)
		free(res[--k]);
	free(res);
}

int	fill_split(char **res, const char *s, char c, size_t words)
{
	size_t	i;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	while (s[i] && k < words)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
		{
			res[k] = dup_word(s, start, i);
			if (!res[k])
				return (free_split(res, k), 0);
			k++;
		}
	}
	res[k] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (!fill_split(res, s, c, words))
		return (NULL);
	return (res);
}
