#include "../mini_struct/mini.h"

void	transform_str(void)
{
	if (!is_valid())
	{
		ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
		printf("Not valid!\n");
		return ;
	}
	printf("valid!\n");
	ft_cmdlstclear(&mini()->cmd, ft_cmdlstdelone);
}
