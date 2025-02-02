/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:02:55 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/02 21:14:55 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"

static void	update_env(t_list **lst, t_string s)
{
	t_list	*tmp;

	if (!lst || !*s)
		return ;
	tmp = *lst;
	if (tmp->content)
		free(tmp->content);
	tmp->content = ft_strdup(s);
}

static void	update_pwd(t_string path, t_list **lst, bool to_free)
{
	t_string	s;
	t_string	p;
	t_list		*tmp;

	tmp = ft_lstgetlst(lst, "OLDPWD=");
	p = ft_lsthas(mini()->env, "PWD");
	s = ft_strjoin("OLDPWD", p);
	if (!tmp)
		ft_lstadd_back(lst, ft_lstnew(s));
	else
		update_env(&tmp, s);
	tmp = ft_lstgetlst(lst, "PWD=");
	if (s)
		free(s);
	s = ft_strjoin("PWD=", path);
	if (!tmp)
		ft_lstadd_back(lst, ft_lstnew(s));
	else
		update_env(&tmp, s);
	if (s)
		free(s);
	if (to_free)
		free(path);
}

static void	home(void)
{
	t_string	s;
	int			i;

	s = ft_lsthas(mini()->env, "HOME=");
	if (!s || !*s)
		return (perror("Home not set"), (void)s);
	s++;
	i = chdir(s);
	if (i == -1)
		perror("CD");
	update_pwd(s, &mini()->env, false);
	update_pwd(s, &mini()->exp, false);
}

static bool	cd_(void)
{
	t_string	s;

	s = ft_lsthas(mini()->env, "OLDPWD=");
	if (!s || !*s)
		return (ft_putstr_fd("OLDPWD NOT SET\n", 2), true);
	s++;
	if (chdir(s) >= 0)
		return (update_pwd(getcwd(NULL, 0), &mini()->env, true), \
			update_pwd(getcwd(NULL, 0), &mini()->exp, true), \
			false);
	else
		return (perror(s), true);
}

void	cd_execute(t_string *matrix)
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
		return (update_pwd(getcwd(NULL, 0), &mini()->env, true), \
			update_pwd(getcwd(NULL, 0), &mini()->exp, true), \
			(void)*matrix);
	else if (chdir(matrix[0]) < 0)
		return (perror(matrix[0]), (void)*matrix);
	if (i)
		return ;
	s = getcwd(NULL, 0);
	printf("%s \n", s);
	free(s);
}
