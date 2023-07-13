int	set_v1(t_stack *a, t_stack *b)
{
	int	count;

	(void)b;
	count = 0;
	count += ps_rotate(a);
	return (count);
}

int	set_v2(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	count += ps_push(a, b);
	return (count);
}

int	set_v3(t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	count += ps_push(a, b);
	count += ps_rotate(b);
	return (count);
}
