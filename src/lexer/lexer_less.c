#include "lexer.h"

int		lexer_less(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token_append(token, str[0]);
	if (*(str + 1) == '&')
	{
		token->type = TK_LESSAND;
		token_append(token, str[1]);
		return (lexer_lessand(alst, str + 2));
	}
	else if (*(str + 1) == '<')
	{
		token->type = TK_DLESS;
		token_append(token, str[1]);
		return (ft_tokenize(&(*alst)->next, str + 2, DEFAULT));
	}
	else
	{
		token->type = TK_LESS;
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	}
}