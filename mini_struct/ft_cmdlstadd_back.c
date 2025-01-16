#include "mini.h"

static t_cmd	*ft_lst_last(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_cmdlstadd_back(t_cmd **lst, t_cmd *n)
{
	t_cmd	*last;

	last = ft_lst_last(*lst);
	if (!last)
		*lst = n;
	else
		last->next = n;
}
