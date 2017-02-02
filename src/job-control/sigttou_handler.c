/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigttou_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:14:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/08 13:24:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigttou_handler(int signo)
{
	(void)signo;
	DG("got SIGTTOU, pid=%i, pgid=%i", getpid(), getpgid(getpid()));
}
