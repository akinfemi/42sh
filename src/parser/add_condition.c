/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:06:16 by ariard            #+#    #+#             */
/*   Updated: 2017/03/22 15:33:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		iscondition(t_btree **ast, t_list **lst)
{
	t_astnode	*node;

	node = NULL;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_NEWLINE || node->type == TK_SEMI
			|| node->type == TK_AMP || node->type == TK_PIPE
			|| node->type == TK_AND_IF || node->type == TK_OR_IF)
			&& iscondition(&(*ast)->right, lst) == 1)
			return (1);
		if ((node->type == TK_IF || node->type == TK_ELIF
			|| node->type == TK_ELSE) && node->full == 0)
			return (1);
	}
	return (0);
}

int		iscondition_branch(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_ELIF)
			&& (token->type == TK_ELIF || token->type == TK_ELSE)
			&& node->nest == 0)
			return (1);
	}
	return (0);
}

int		add_condition_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	token = (*lst)->content;
	node = (*ast)->item;
	if (token->type == TK_IF && (node->type == TK_IF || node->type == TK_ELIF
		|| node->type == TK_ELSE))
		node->nest++;
	if (token->type == TK_FI && (node->type == TK_IF || node->type == TK_ELIF
		|| node->type == TK_ELSE) && node->nest > 0)
		node->nest--;
	else if (token->type == TK_FI && (node->type == TK_IF
		|| node->type == TK_ELIF || node->type == TK_ELSE))
		return ((node->full = 1));
	if (token->type == TK_THEN)
		return (add_cmd(&(*ast)->right, lst));
	else if (!(*ast)->right)
		return (add_cmd(&(*ast)->left, lst));
	else
		return (add_cmd(&(*ast)->right, lst));
	return (0);
}

int		add_condition_sep(t_btree **ast, t_list **lst)
{
	if (!(*ast)->right)
		return (add_sep(&(*ast)->left, lst));
	else
		return (add_sep(&(*ast)->right, lst));
	return (0);
}

int		add_if(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_IF;
	token->type = TK_ELIF;
	add_cmd(&(*ast)->right, lst);
	return (0);
}
