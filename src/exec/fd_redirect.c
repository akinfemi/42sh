/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:04:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 15:24:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_redirect(t_data *data)
{
	if (data->exec.fdin != STDIN)
	{
		dup2(data->exec.fdin, STDIN);
		close(data->exec.fdin);
	}
	if (data->exec.fdout != STDOUT)
	{
		dup2(data->exec.fdout, STDOUT);
		close(data->exec.fdout);
	}
}