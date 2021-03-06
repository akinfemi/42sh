/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pset_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:02:01 by wescande          #+#    #+#             */
/*   Updated: 2017/03/20 16:26:37 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pset_subshell(t_process *p, t_btree *ast)
{
	p->data.subshell.content = btree_map(ast->right, &node_copy);
	p->type = PROCESS_SUBSHELL;
	return (0);
}
