/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:09:42 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/05 20:56:55 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_struct/mini.h"
#include "ft_signals.h"
#include <readline/readline.h>
#include <signal.h>
#include <unistd.h>

void	load_signals(void)
{
	static struct sigaction	sig;

	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sig.sa_sigaction = sig_handler;
	sigaction(SIGINT, &sig, NULL);
	if (mini()->sig == 1)
		signal(SIGQUIT, SIG_IGN);
	if (mini()->sig == 2)
	{
		sig.sa_sigaction = sig_handler_here;
		signal(SIGQUIT, SIG_IGN);
	}
	if (mini()->sig == 3)
		sig.sa_sigaction = sig_handler_pipe;
	rl_event_hook = 0;
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
		return ;
}

void	sig_handler_here(int signum, siginfo_t *sig, void *s)
{
	(void)s;
	(void)sig;
	if (signum == SIGINT)
	{
		rl_done = 1;
	}
	if (signum == SIGQUIT)
		return ;
}

void	sig_handler_pipe(int signum, siginfo_t *sig, void *s)
{
	(void)s;
	(void)sig;
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		mini()->sig = 1;
		mini()->exit_code = 130;
	}
	if (signum == SIGQUIT)
		return (ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO));
}
