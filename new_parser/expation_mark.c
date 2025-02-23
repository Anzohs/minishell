#include "new_parse.h"
#include "../mini_struct/mini.h"

static int get_type(t_fd **f, t_string name)
{
    int i;
    int c;

    i = -1;
    c = 0;
    while (name[++i])
    {
        if ((name[i] == '"' || name[i] == '\'') && !c)
			c = name[i];
		else if (name[i] == c)
			c = 0;
		else if (!c && (name[i] == '<' || name[i] == '>'))
		{
			if (name[i] == '>' && name[i + 1] == '>')
			{
				(*f)->type = APPEND;
				i++;
			}
			else if (name[i] == '<' && name[i + 1] == '<')
			{
				(*f)->type = HEREDOC;
				i++;
			}
			else if (name[i] == '>')
				(*f)->type = CREATE;
			else
				(*f)->type = REVERSE;
			i++;
			while (name[i] == ' ')
				i++;
			break;
        }
    }
    return (i);
}

static void     file_name_clean(t_fd **f, t_string *name)
{
    t_string s;
    int     i;

    i = get_type(f, *name);
    s = ft_substr(*name, i, ft_strlen(*name) - i);
    free(*name);
    *name = s;
}

static void    fd_expantions(t_fd **f)
{
    t_fd    *f_d;
    if (!*f)
        return ;
    f_d = *f;
    while (f_d)
    {
        file_name_clean(&f_d, &f_d->name);
        expantions(&(f_d)->name);
        while (is_expantion((f_d)->name))
	    	(f_d)->name = sub_expantion((f_d)->name, get_var((*f)->name));
        take_quotes(&f_d->name);
        f_d = f_d->next;
    }
}

void    expantion_mark(void)
{
    t_cmd   *lst;

    lst = mini()->cmd;
    while (lst)
    {
        create_matrix(&lst);
        fd_expantions(&lst->fd);
        lst = lst->next;
    }
    execute();
}