/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_case_branch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:33:45 by wescande          #+#    #+#             */
/*   Updated: 2017/03/29 12:22:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_case_branch(t_btree **ast)
{
	t_astnode	*node;
	char		**av;
	t_exec		*exec;

	exec = &data_singleton()->exec;
	if (EXEC_IS_CASE_BRANCH(exec->attrs) || !exec->case_pattern
		|| !*exec->case_pattern)
		return (0);
	node = (*ast)->item;
	av = token_to_argv(node->data.cmd.token, 1);
	if (av && (ft_strcmp(av[0], ((char **)exec->case_pattern)[0]) == 0))
	{
		exec->attrs |= EXEC_CASE_BRANCH;
		ft_tabdel(&exec->case_pattern);
		ft_exec(&(*ast)->right);
	}
	ft_tabdel(&av);
	return (0);
}
