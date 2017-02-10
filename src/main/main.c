/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:40:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/10 00:36:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		interactive_shell()
{
	t_list	*token;
	t_list	*ltoken;
	t_lexer	lexer;
	t_btree	*ast;

	lexer.pos = 0;
	lexer.state = DEFAULT;
	lexer.str = NULL;
	token = NULL;
	lexer.stack = NULL;
	ast = NULL;
	do {
		if (lexer.stack && *(int*)lexer.stack->content == BACKSLASH)
			pop(&lexer.stack);
		ft_strappend(&lexer.str, readline(stack_to_prompt(lexer.stack)));
		DG("[{mag}%s{eoc}]", lexer.str);
		ltoken = ft_lstlast(token);
		lexer_lex((token ? &ltoken : &token), &lexer);
		token_print(token);
	} while (lexer.stack);
	DG("after lexing");
	token_print(token);
	if (ft_parse(&ast, &token))
		return (1);
	btree_print(STDBUG, ast, &ft_putast);
	if (ft_exec(&ast))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_data	*data;

	data = data_singleton();
	setlocale(LC_ALL, "");
	shell_init(ac, av);
	DG("{inv}{bol}{gre}start of shell{eoc} pid=%i pgrp=%i job_control is %s", getpid(), getpgrp(), SH_HAS_JOBC(data->opts) ? "ON" : "OFF");
	if (SH_IS_INTERACTIVE(data->opts))
	{
		while (1)
			interactive_shell();
	}
	return (0);
}
