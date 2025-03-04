/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:02:55 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/08 20:35:24 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static void	update_env(t_list **lst, t_string key, t_string value)
{
	t_list		*tmp;
	t_string	s;

	if (!lst || !value || !*value)
		return ;
	tmp = ft_lstgetlst(lst, key);
	s = ft_strjoin(key, value);
	if (!tmp)
		ft_lstadd_back(lst, ft_lstnew(s));
	else
	{
		if (tmp->content)
			free(tmp->content);
		tmp->content = s;
	}
}

static void	update_pwd(t_string path, t_list **lst, bool to_free)
{
	t_string	oldpwd;

	oldpwd = ft_lsthas(mini()->env, "PWD=");
	if (*oldpwd)
		oldpwd++;
	update_env(lst, "OLDPWD=", oldpwd);
	update_env(lst, "PWD=", path);
	if (to_free)
		free(path);
}

static void	home(void)
{
	t_string	s;
	int			i;

	s = ft_lsthas(mini()->env, "HOME=");
	if (!s || !*s)
		return (perror("Home not set"), mini()->exit_code = 1, (void)s);
	s++;
	i = chdir(s);
	if (i == -1)
		return (mini()->exit_code = 1, perror("CD"));
	update_pwd(s, &mini()->exp, false);
	update_pwd(s, &mini()->env, false);
	mini()->exit_code = 0;
}

static bool	cd_(void)
{
	t_string	s;

	s = ft_lsthas(mini()->env, "OLDPWD=");
	if (!s || !*s)
		return (ft_putstr_fd("OLDPWD NOT SET\n", 2), mini()->exit_code = 1,
			true);
	s++;
	if (chdir(s) >= 0)
		return (update_pwd(getcwd(NULL, 0), &mini()->env, true),
			update_pwd(getcwd(NULL, 0), &mini()->exp, true), false);
	else
		return (perror(s), mini()->exit_code = 1, true);
}

void	cd_execute(t_string *matrix, int fd)
{
	bool		i;
	t_string	s;

	i = false;
	if (matrix_len(matrix) > 1)
		return (perror("Too many arguments"), (void)s);
	if (!matrix || !*matrix || !ft_strcmp(matrix[0], "")
		|| !ft_strcmp(matrix[0], "~"))
		return (home(), (void)s);
	else if (!ft_strcmp(matrix[0], "-"))
		i = cd_();
	else if (chdir(matrix[0]) >= 0)
		return (update_pwd(getcwd(NULL, 0), &mini()->exp, true),
			update_pwd(getcwd(NULL, 0), &mini()->env, true), (void)*matrix);
	else if (chdir(matrix[0]) < 0)
		return (perror(matrix[0]), mini()->exit_code = 1, (void)*matrix);
	if (i)
		return ;
	s = getcwd(NULL, 0);
	ft_putendl_fd(s, fd);
	printf("%s \n", s);
	free(s);
}
