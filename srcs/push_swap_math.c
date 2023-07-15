int	ft_abs(int a);

int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int	ps_abs_sum(int a, int b)
{
	return (ft_abs(a) + ft_abs(b));
}

