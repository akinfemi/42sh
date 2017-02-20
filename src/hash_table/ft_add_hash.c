/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:20:11 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/18 14:38:21 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int		ft_add_hash(t_process *p)
{
	int		id;
	t_hash	hash;

	if (!(hash.path = ft_findexec(
						ft_getenv(data_singleton()->env, "PATH"), p->av[0])))
		return (0);
	hash.key = ft_strdup(p->av[0]);
	id = ft_hash_str(p->av[0]);
	ft_lsteadd(&(g_hash[id]), ft_lstnew(&hash, sizeof(t_hash)));
	p->path = ft_strdup(hash.path);
	return (1);
}