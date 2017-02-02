/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigttin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:14:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/09 16:37:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigttin_handler(int signo)
{
	(void)signo;
	DG("got SIGTTIN, pid=%i, pgid=%i", getpid(), getpgrp());
}
