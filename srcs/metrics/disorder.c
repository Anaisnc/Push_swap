float	compute_disorder(int *a, int size)
{
	int		i;
	int		j;
	int		mistakes;
	float	total_pairs;

	if (size < 2)
		return (0.0);
	mistakes = 0;
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (a[i] > a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	total_pairs = (float)(size * (size - 1)) / 2;
	return ((float)mistakes / total_pairs);
}
