/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:09:42 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/02 17:22:38 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../mini_struct/mini.h"

void	load_signals(void)
{
	static struct sigaction	sig;

	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sig.sa_sigaction = sig_handler;
	sigaction(SIGINT, &sig, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_handler(int signum, siginfo_t *sig, void *s)
{
	(void)s;
	(void)sig;
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
		mini()->sig = 1;
	}
	if (signum == SIGQUIT)
		return;
}

void	sig_handler_here(int signum, siginfo_t *sig, void *s)
{
	(void)s;
	(void)sig;
	if (signum ==  SIGINT)
	{
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		mini()->sig = 1;
	}
	if (signum == SIGQUIT)
		return ;
}
