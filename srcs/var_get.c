int	get_v1(t_stack *a, t_stack *b)
{
	int	count;

	(void)b;
	count = 0;
	count += ps_rrotate(a);
	return (count);
}

int	get_v2(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	count += ps_push(b, a);
	return (count);
}

int	get_v3(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	count += ps_rrotate(b);
	count += ps_push(b, a);
	return (count);
}
