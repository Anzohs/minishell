#include "mini.h"

int	ft_cmdlst_len(t_cmd **lst)
{
	t_cmd	*tmp;
	int		i;

	if (!lst || !*lst)
		return (0);
	tmp = *lst;
	i = 0;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}
