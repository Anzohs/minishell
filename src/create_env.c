/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:22:10 by malourei          #+#    #+#             */
/*   Updated: 2024/11/18 23:52:27 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	create_pwd(char **strs, char *pwd)
{
	strs[0] = ft_calloc(sizeof(char), (ft_strlen(pwd) + 6));
	if (!strs[0])
	{
		ft_free_strs(strs, 1);
		free(pwd);
		exit (1);
	}
	ft_strcpy(strs[0], "PWD=");
	ft_strcat(strs[0], pwd);
}

static void	create_old_pwd(char **strs, char *pwd)
{
	char	*temp;
	char	*temp2;

	temp2 = ft_calloc(sizeof(char), ft_strlen(pwd) + 1);
	if (!temp2)
	{
		ft_free_strs(strs, 2);
		free(pwd);
		exit (1);
	}
	ft_strcpy(temp2, pwd);
	temp = ft_strrchr(temp2, '/');
	strs[1] = ft_calloc(sizeof(char), (ft_strlen(temp) + 8));
	if (!strs[1])
	{
		ft_free_strs(strs, 2);
		free(pwd);
		free(temp2);
		exit (1);
	}
	ft_strcpy(strs[1], "OLDPWD=");
	ft_strcat(strs[1], temp);
	free(temp2);
}

static void	create_shlvl(char **strs, char *pwd)
{
	strs[2] = ft_calloc(sizeof(char), 8);
	if (!strs[2])
	{
		ft_free_strs(strs, 3);
		free(pwd);
		exit (1);
	}
	ft_strcpy(strs[2], "SHLVL=1");
}

static void	create_under(char **strs, char *pwd)
{
	strs[3] = ft_calloc(sizeof(char), (ft_strlen(pwd) + 15));
	if (!strs[3])
	{
		ft_free_strs(strs, 4);
		free(pwd);
		exit (1);
	}
	ft_strcpy(strs[3], "_=");
	ft_strcat(strs[3], pwd);
	ft_strcat(strs[3], "/./minishell");
}

void	creat_env(t_mini *mini)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		mini->super_env = ft_calloc(sizeof(char *), 4);
		if (!mini->super_env)
		{
			free(mini->super_env);
			free(pwd);
			exit (1);
		}
		create_pwd(mini->super_env, pwd);
		create_old_pwd(mini->super_env, pwd);
		create_shlvl(mini->super_env, pwd);
		create_under(mini->super_env, pwd);
		free(pwd);
		mini->super_env[4] = NULL;
	}
	else
	{
		write(1, "MAXI MACHO\n", 12);
	}
}
