/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:56:49 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 02:16:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_backslash(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	lexer->state = DEFAULT;
	if (lexer->str[lexer->pos + 1] == 0)
	{
		lexer->str[lexer->pos] = 0;
		push(&lexer->stack, BACKSLASH);
		return (0);
	}
	lexer->pos++;
	token_append(token, lexer, 1, 1);
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
