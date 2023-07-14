int	ft_sptsize(char **spt)
{
	int	i;

	i = 0;
	while (spt[i])
		i++;
	return (i);
}
