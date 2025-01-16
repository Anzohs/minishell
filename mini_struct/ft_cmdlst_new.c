#include "mini.h"

t_cmd	*ft_cmdlst_new(char *cmd, char *arg)
{
	t_cmd	*list;

	list = (t_cmd *)ft_calloc(1, sizeof(*list));
	if (!list)
		return (NULL);
	list->cmd = ft_strdup(cmd);
	if (!list->cmd)
	{
		free(list);
		exit (0);
	}
	list->arg = ft_strdup(arg);
	if (!list->arg)
	{
		//delone();
		exit(0);
	}
	list->next = NULL;
	return (list);
}
