
#include "../mini_struct/mini.h"

void	env_execute(void)
{
	t_list *tmp;

	tmp = mini()->env;
	while (tmp)
	{
		ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
}