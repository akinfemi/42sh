/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_ctrl_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/07 18:12:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_key_ctrl_d(t_data *data, char *buf)
{
	(void)data;
	(void)buf;
	data_exit(data);
	ft_putendl("exit");
	exit(0);
}
