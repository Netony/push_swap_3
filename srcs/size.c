#include <stdlib.h>

int	ft_sptsize(char **spt)
{
	int	i;

	i = 0;
	while (spt[i])
		i++;
	return (i);
}

void	ft_sptdel(char **spt)
{
	int	i;

	i = 0;
	while (spt[i])
		free(spt[i++]);
	free(spt);
}
