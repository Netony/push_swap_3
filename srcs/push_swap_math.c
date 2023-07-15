int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int	get_rotate(int r, int n)
{
	if (r > (n - 1) / 2)
		r -= n;
	return (r);
}
