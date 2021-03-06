/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_for.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 00:49:20 by wescande          #+#    #+#             */
/*   Updated: 2017/03/28 20:29:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define FORERR_0	": `%s' not a valid identifier"

int				plaunch_for(t_process *p)
{
	t_ld		*temp;
	int			i;
	char		**av;
	char		*var;

	temp = p->data.d_for.token;
	var = ((char **)temp->content)[0];
	if (!word_is_assignment(temp->content))
		return (SH_ERR(FORERR_0, var));
	i = 0;
	av = token_to_argv(temp, 1);
	data_singleton()->exec.job.attrs &= ~JOB_BG;
	while (av[++i])
	{
		builtin_setenv("setenv", (char*[]){"local", var, av[i], 0},
				NULL);
		ft_exec(&p->data.d_for.content);
	}
	ft_tabdel(&av);
	return (1);
}
