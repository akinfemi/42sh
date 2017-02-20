/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_get_opts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:04:48 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/20 21:00:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	shell_parse_long_opt(char *str)
{
	if (ft_strcmp("no-jobcontrol", str) == 0)
		data_singleton()->opts &= ~SH_OPTS_JOBC;
}

static void	shell_parse_short_opt(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (*str == 'c')
		{
			data_singleton()->opts |= SH_OPTS_LC;
			data_singleton()->opts &= ~SH_OPTS_JOBC;
			data_singleton()->opts &= ~SH_INTERACTIVE;
		}
		i++;
	}
}

void		shell_get_opts(int ac, char **av)
{
	int		i;

	i = 1;
	if (isatty(STDIN))
		data_singleton()->opts |= SH_INTERACTIVE;
	while (i < ac && av[i][0] == '-')
	{
		if (ft_strcmp(av[i], "--") == 0)
		{
			i++;
			break ;
		}
		if (av[i][1] == '-')
			shell_parse_long_opt(av[i] + 2);
		else
			shell_parse_short_opt(av[i] + 1);
		i++;
	}
}
