#include "execute.h"

void	pwd_execute(void)
{
	t_string	m;

	m = getcwd(NULL, 0);
	printf("%s \n", m);
	free(m);
}
