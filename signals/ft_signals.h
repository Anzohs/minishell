/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malourei <malourei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:09:55 by hladeiro          #+#    #+#             */
/*   Updated: 2025/03/06 19:26:32 by malourei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

# include "../libs.h"

extern int			g_sig;

void	load_signals(void);
void	sig_handler(int signum, siginfo_t *sig, void *s);
void	sig_handler_here(int signum, siginfo_t *sig, void *s);
void	sig_handler_pipe(int signum, siginfo_t *sig, void *s);
#endif
