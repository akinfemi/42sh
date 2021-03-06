/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:33:48 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:19:26 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t		ft_ld_size(t_ld *ld)
{
	size_t	size;

	size = 0;
	ld = ft_ld_front(ld);
	while (ld)
	{
		++size;
		ld = ld->next;
	}
	return (size);
}
