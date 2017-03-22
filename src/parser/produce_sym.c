/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produce_sym.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:58:34 by ariard            #+#    #+#             */
/*   Updated: 2017/03/22 18:15:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_prodmatch			g_prodmatch[] =
{
	{TK_WORD, TK_DLESS, HERE_END},
	{TK_WORD, TK_DLESSDASH, HERE_END},
	{TK_WORD, TK_LESS, FILENAME},
	{TK_WORD, TK_LESSAND, FILENAME},
	{TK_WORD, TK_GREAT, FILENAME},
	{TK_WORD, TK_GREATAND, FILENAME},
	{TK_WORD, TK_DGREAT, FILENAME},
	{TK_WORD, TK_LESSGREAT, FILENAME},
	{TK_WORD, TK_CLOBBER, FILENAME},
	{TK_WORD, CMD_WORD, CMD_SUFFIX},
	{TK_WORD, CMD_NAME, CMD_SUFFIX},
	{TK_WORD, CMD_SUPERIOR, CMD_SUFFIX},
	{TK_WORD, PIPE_SEMI_SEQUENCE, CMD_SUFFIX},
	{TK_WORD, LINEBREAK, CMD_NAME},
	{TK_WORD, TK_BANG, CMD_NAME},
	{TK_WORD, TK_PIPE, CMD_NAME},
	{TK_WORD, AND_OR, CMD_NAME},
	{TK_WORD, AND_OR_MAJOR, CMD_NAME},
	{TK_WORD, TK_WHILE, CMD_NAME},
	{TK_WORD, TK_UNTIL, CMD_NAME},
	{TK_WORD, TK_DO, CMD_NAME},
	{TK_WORD, TK_RBRACE, CMD_NAME},
	{TK_WORD, TK_IF, CMD_NAME},
	{TK_WORD, TK_THEN, CMD_NAME},
	{TK_WORD, TK_ELIF, CMD_NAME},
	{TK_WORD, TK_ELSE, CMD_NAME},
	{TK_WORD, COMPOUND_LIST, CMD_NAME},
	{TK_WORD, CASE_LIST_NS, CMD_NAME},
	{TK_WORD, COMPLETE_CONDITION, CMD_NAME},
	{TK_WORD, CONDITION, CMD_NAME},
	{TK_WORD, NEWLINE_LIST, CMD_NAME},
	{TK_WORD, TK_BANG, CMD_NAME},
	{TK_WORD, SEQUENCE, CMD_NAME},
	{TK_WORD, SEPARATOR_OP, CMD_NAME},
	{TK_WORD, TK_PAREN_OPEN, CMD_NAME},
	{TK_WORD, TK_LBRACE, CMD_NAME},
	{TK_WORD, CASE_LIST, PATTERN},
	{TK_WORD, PATTERN_CASE, PATTERN},
	{TK_WORD, COMPLETE_COMMANDS, CMD_NAME},
	{TK_ASSIGNMENT_WORD, TK_BANG, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, LINEBREAK, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_PAREN_OPEN, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_LBRACE, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_BANG, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, SEPARATOR_OP, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_WHILE, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_UNTIL, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_DO, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_FOR, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_IF, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_THEN, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_ELIF, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, TK_ELSE, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, NEWLINE_LIST, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, CMD_NAME, CMD_SUFFIX},
	{TK_ASSIGNMENT_WORD, CMD_SUPERIOR, CMD_SUFFIX},
	{TK_ASSIGNMENT_WORD, COMPOUND_LIST, CMD_SUFFIX},
	{TK_ASSIGNMENT_WORD, COMPLETE_CONDITION, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, CONDITION, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, AND_OR, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, AND_OR_MAJOR, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, PIPE_SEMI_SEQUENCE, CMD_SUFFIX},
	{TK_ASSIGNMENT_WORD, SEQUENCE, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, COMPLETE_COMMANDS, CMD_PREFIX},
	{TK_ASSIGNMENT_WORD, CMD_WORD, CMD_SUFFIX},
	{TK_NAME, TK_BANG, FNAME},
	{TK_NAME, LINEBREAK, FNAME},
	{TK_NAME, TK_PAREN_OPEN, FNAME},
	{TK_NAME, TK_LBRACE, FNAME},
	{TK_NAME, TK_BANG, FNAME},
	{TK_NAME, SEPARATOR_OP, FNAME},
	{TK_NAME, NEWLINE_LIST, FNAME},
	{TK_NAME, TK_FOR, NAME},
	{TK_NEWLINE, CASE_LIST_NS, NEWLINE_LIST},
	{TK_NEWLINE, TK_DO, NEWLINE_LIST},
	{TK_NEWLINE, TK_PAREN_CLOSE, NEWLINE_LIST},
	{TK_NEWLINE, TK_RBRACE, CMD_NAME},
	{TK_NEWLINE, TK_IN, NEWLINE_LIST},
	{TK_NEWLINE, TK_WHILE, NEWLINE_LIST},
	{TK_NEWLINE, TK_UNTIL, NEWLINE_LIST},
	{TK_NEWLINE, TK_FOR, NEWLINE_LIST},
	{TK_NEWLINE, TK_IF, NEWLINE_LIST},
	{TK_NEWLINE, TK_FI, NEWLINE_LIST},
	{TK_NEWLINE, TK_ELIF, NEWLINE_LIST},
	{TK_NEWLINE, TK_ELSE, NEWLINE_LIST},
	{TK_NEWLINE, TK_THEN, NEWLINE_LIST},
	{TK_NEWLINE, FUNC_NAME, NEWLINE_LIST},
	{TK_NEWLINE, CMD_NAME, NEWLINE_LIST},
	{TK_NEWLINE, COMPLETE_COMMANDS, NEWLINE_LIST},
	{TK_NEWLINE, LINEBREAK, NEWLINE_LIST},
	{TK_NEWLINE, TK_BANG, NEWLINE_LIST},
	{TK_NEWLINE, TK_PAREN_OPEN, NEWLINE_LIST},
	{TK_NEWLINE, TK_LBRACE, NEWLINE_LIST},
	{TK_NEWLINE, CMD_SUPERIOR, LINEBREAK},
	{TK_NEWLINE, PIPE_SEMI_SEQUENCE, LINEBREAK},
	{TK_NEWLINE, PIPE_CLOSE_SEQUENCE, LINEBREAK},
	{TK_NEWLINE, SEQUENCE, NEWLINE_LIST},
	{TK_NEWLINE, CASE_LIST_NS, NEWLINE_LIST},
	{TK_NEWLINE, COMPOUND_LIST, NEWLINE_LIST},
	{TK_NEWLINE, COMPLETE_CONDITION, NEWLINE_LIST},
	{TK_NEWLINE, CONDITION, NEWLINE_LIST},
	{TK_NEWLINE, FOR_WORDLIST, NEWLINE_LIST},
	{TK_NEWLINE, SEQUENTIAL_SEP, NEWLINE_LIST},
	{TK_NEWLINE, PROGRAM, NEWLINE_LIST},
	{TK_SEMI, CMD_SUPERIOR, SEPARATOR_OP},
	{TK_SEMI, LIST, SEPARATOR_OP},
	{TK_SEMI, PIPE_SEMI_SEQUENCE, SEPARATOR_OP},
	{TK_SEMI, PIPE_CLOSE_SEQUENCE, SEPARATOR_OP},
	{TK_AMP, CMD_SUPERIOR, SEPARATOR_OP},
	{TK_AMP, LIST, SEPARATOR_OP},
	{TK_AMP, PIPE_SEMI_SEQUENCE, SEPARATOR_OP},
	{TK_AMP, PIPE_CLOSE_SEQUENCE, SEPARATOR_OP},
	{0, 0, 0},
};

int				produce_sym(t_list **stack, t_sym *new_sym, t_list **lst)
{
	t_token		*token;
	t_sym		*head;
	int			i;

	if (!*stack || !*lst)
		return (1);
	token = (*lst)->content;
	head = (*stack)->content;
	i = 0;
	*new_sym = 0;
	while (g_prodmatch[i].new_sym)
	{
		if (token->type == g_prodmatch[i].token
			&& *head == g_prodmatch[i].stack)
			*new_sym = g_prodmatch[i].new_sym;
		i++;
	}
	if (!*new_sym)
		*new_sym = token->type;
	return (0);
}
