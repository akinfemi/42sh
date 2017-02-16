/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:15:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 19:54:11 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_comment(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	if (lexer->str[lexer->pos] == '\n')
		return (lexer_lex(&(*alst)->next, lexer));
	return (lexer_comment(alst, lexer));
}