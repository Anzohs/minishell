/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:09:55 by hladeiro          #+#    #+#             */
/*   Updated: 2025/02/01 20:16:41 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNALS_H
# define FT_SIGNALS_H

# include "../libs.h"

void	load_signals(void);
void	sig_handler(int signum, siginfo_t *sig, void *s);
void	sig_handler_here(int signum, siginfo_t *sig, void *s);
#endif
