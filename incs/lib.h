#ifndef LIB_H
# define LIB_H

#include "../libft/incs/libft.h"

#include "toklen.h"

int		ft_strcmp(char *s1, char *s2);

int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

int		ft_sptsize(char **spt);
void	ft_sptdel(char **spt);

#endif
