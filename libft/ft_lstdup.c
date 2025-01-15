#include "libft.h"

void	ft_lstdup(t_list **list, t_list **head)
{
  	t_list	*lst;
    t_list	*tmp;
    char	*content;

  	tmp = *list;
    while (tmp)
    {
      content = ft_strdup(tmp->content);
      if (!content)
      {
        ft_lstclear(head, free);
        return ;
      }
      lst = ft_lstnew(content);
      ft_lstadd_back(head, lst);
      tmp = tmp->next;
    }
}