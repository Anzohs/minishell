/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:51:00 by hladeiro          #+#    #+#             */
/*   Updated: 2025/01/14 22:51:01 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_struct/mini.h"

void	prin_list(t_list *head) {
	t_list	*lst;

	lst = head;
	while (lst) {
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}

int	main(int ac, char **av, char **env)
{
	//mini()->readline = readline("shell");
	(void)av;
	(void)ac;
	m_copy_env(env);
	ft_lstdup(&mini()->exp, &mini()->env);
	prin_list(mini()->env);
	write(1, "\n", 1);
	prin_list(mini()->exp);
	ft_lstclear(&mini()->env, free);
	ft_lstclear(&mini()->exp, free);
	return (0);
}
