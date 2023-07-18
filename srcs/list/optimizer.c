int	optimizer(t_list *lst)
{
}

void	ft_lstdel_node(t_list **lst, t_list *node)
{
	t_list	*cur;
	t_list	*prev;

	cur = *lst;
	while (cur)
	{
		if (cur == node)
		{
			if (cur == *lst)
			{
				*lst = cur->next;
				free(cur);
				return ;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				return ;
			}
		}
		prev = cur;
		cur = cur->next;
	}
}
