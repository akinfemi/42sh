/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:17:14 by ariard            #+#    #+#             */
/*   Updated: 2017/03/22 15:29:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		isloop(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == TK_FOR && (token->type == TK_NEWLINE
			|| token->type == TK_SEMI) && node->pattern == 0)
			return (1);
		if (node->type == TK_FOR && (token->type == TK_WORD
			|| token->type == TK_NAME) && node->pattern == 0)
			return (0);
		if ((node->type == TK_NEWLINE || node->type == TK_SEMI
			|| node->type == TK_AMP || node->type == TK_PIPE
			|| node->type == TK_AND_IF || node->type == TK_OR_IF)
			&& isloop(&(*ast)->right, lst) == 1)
			return (1);
		if ((node->type == TK_WHILE || node->type == TK_UNTIL
			|| node->type == TK_FOR) && node->full == 0)
			return (1);
	}
	return (0);
}

int		add_loop_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	token = (*lst)->content;
	node = (*ast)->item;
	if (token->type == TK_DO && node->type == TK_FOR)
		node->pattern = 1;
	if ((token->type == TK_WHILE || token->type == TK_UNTIL
		|| token->type == TK_FOR) && (node->type == TK_WHILE
		|| node->type == TK_UNTIL || node->type == TK_FOR))
		node->nest++;
	if (token->type == TK_DONE && (node->type == TK_WHILE
		|| node->type == TK_UNTIL || node->type == TK_FOR) && node->nest > 0)
		node->nest--;
	else if (token->type == TK_DONE && (node->type == TK_WHILE
		|| node->type == TK_UNTIL || node->type == TK_FOR) && node->nest == 0)
		return ((node->full = 1));
	if (token->type == TK_DO && node->nest == 0)
		return (add_cmd(&(*ast)->right, lst));
	else if (!(*ast)->right && isloop(&(*ast)->left, lst) != 2)
		return (add_cmd(&(*ast)->left, lst));
	else
		return (add_cmd(&(*ast)->right, lst));
	return (0);
}

int		add_loop_sep(t_btree **ast, t_list **lst)
{
	t_astnode	*node;

	node = NULL;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == TK_FOR && node->pattern == 0)
			return (0);
	}
	if (!(*ast)->right)
		return (add_sep(&(*ast)->left, lst));
	else
		return (add_sep(&(*ast)->right, lst));
	return (0);
}
