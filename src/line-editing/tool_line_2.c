/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_line_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:07:52 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/22 17:20:05 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_clear_window()
{
	pid_t	soon_pid;
	char	*tab_str[2] = {(char *){"/usr/bin/clear"}, NULL};

	soon_pid = fork();
	if (soon_pid != 0)
		wait(NULL);
	else
		execve("/usr/bin/clear", tab_str, data_singleton()->env);
}

void	ft_printall(char *str, size_t *pos)
{
	size_t	pos_tmp;
	int			ret;

	if (read(0, &ret, sizeof(int)) == -1 || ret != 126 || !str)
		return ;
	ft_clear_window();
	ft_prompt();
	sleep(1);
	pos_tmp = *pos;

	ft_putstr("\033[31m");
	ft_puttermcaps("cd");
	ft_puttermcaps("sc");
	ft_putstr(str);
	while (42)
	{
		ret = 0;
		read(0, &ret, sizeof(int));
		if (ret == TOUCHE_F6)
		{
			ret = 0;
			if (read(0, &ret, sizeof(int)) && ret == 126)
				break ;
		}
	}
	ft_puttermcaps("rc");
	ft_puttermcaps("cd");
	ft_putstr("\033[37m");
	--(*pos);
	ft_get_beggin(str, pos);
	ft_current_str(str, *pos);
	ft_get_next_str(str, pos);
	if (!str[*pos])
		--(*pos);
	ft_putnc('\b', *pos - pos_tmp + 1);
	*pos = pos_tmp;
}

void	ft_get_beggin_with_curs(char *str, size_t *pos)
{
	while ((*pos) && str[(*pos)] != '\n')
	{
		--(*pos);
		ft_puttermcaps("le");
	}
	if (!*pos)
		ft_puttermcaps("le");
	if (str[(*pos)] == '\n')
		++(*pos);
}
