/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 13:59:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	process_free(void *content, size_t content_size)
{
	t_process	*p;

	(void)content_size;
	p = content;
	ft_strdel(&p->path);
	ft_sstrfree(p->av);
	ft_lstdel(&p->redirs, ft_lst_cfree);
	free(p);
}
