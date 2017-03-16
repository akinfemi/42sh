/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pprint_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 16:55:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 16:55:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pprint_cmd(t_process *p)
{
	ft_sstrprint(p->data.cmd.av, ' ');
	return (0);
}
