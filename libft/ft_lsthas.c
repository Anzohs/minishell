#include "libft.h"

char	*ft_lsthas(t_list *lst, const char *str)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, str, ft_strlen(str)))
			return (ft_strchr(tmp->content, '='));
		tmp = tmp->next;
	}
	return ("");
}
