
#include "../ft_search/ft_search.h"

void	free_singlenode(t_node *n)
{
	t_node	*tmp;

	tmp = n;
	n = n->next;
	free(tmp->entry.key);
	free(tmp->entry.value);
	free(tmp);
}
