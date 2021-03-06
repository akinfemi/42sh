/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:17:34 by wescande          #+#    #+#             */
/*   Updated: 2017/03/21 18:12:52 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ld_new(t_ld **alst, void *content)
{
	t_ld	*new;

	if ((new = (t_ld *)ft_malloc(sizeof(t_ld))))
	{
		new->content = content;
		new->prev = NULL;
		new->next = NULL;
		*alst = new;
	}
}
