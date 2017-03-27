/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:07:50 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 03:12:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	data_exit(void)
{
	t_data	*data;
	int		i;

	data = data_singleton();
	ft_strdel(&data->binary);
	ft_sstrfree(data->env);
	ft_sstrfree(data->local_var);
	ft_sstrfree(data->argv);
	lexer_destroy(&data->lexer);
	parser_destroy(&data->parser);
	exec_destroy(&data->exec);
	jobc_destroy(&data->jobc);
	i = -1;
	while (++i < 10)
		ft_lstdel(&data->exec.fd_save[i], ft_lst_cfree);
	ft_lstdel(&data->lst_func, &tree_func_free);
	ft_save_termios(-1);
	ft_free_hash_table();
	free_history_list(data->line.list_beg);
	free(data_singleton());
}
