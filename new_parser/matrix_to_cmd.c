#include "../mini_struct/mini.h"
#include "new_parse.h"

t_string    new_cut(t_string *s, int init, int end)
{
    t_string    new_string;
    int         i;
    int         j;

    if (init >= end)
        return (free(*s), ft_strdup(""));
    new_string = ft_calloc(sizeof(t_string), ft_strlen(*s));
    if (!new_string)
        return (NULL);
    i = -1;
    j = -1;
    while ((*s)[++i])
    {
        if(i < init || i >= end)
            new_string[++j] = (*s)[i];
    }
    free(*s);
    *s = new_string;
}

void    matrix_to_cmd(void)
{
    int i;

    i = -1;
    while (mini()->matrix[++i])
        ft_cmdlstadd_back(&mini()->cmd, ft_cmdlst_new("", mini()->matrix[i]));
    free_env(mini()->matrix);
    redirects_parsing();
}