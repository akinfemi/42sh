/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_touch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:28:49 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/23 13:32:04 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_lecture_3(int ret, char **str, size_t *i)
{
	if (ret == 127 && (*i) > 0)
		ft_suppr(str, i);
	else if (ret == TOUCHE_DELETE && (*str) && (*i) < ft_strlen((*str)))
		ft_del(str, i);
	else
		return (0);
	return (1);
}

static int		ft_lecture_2(int ret, char **str, size_t *i)
{
	if (ret == TOUCHE_F5)
		ft_printall(*str, i);
	else if (ret == TOUCHE_OPT_LEFT || ret == TOUCHE_OPT_RIGHT)
		ft_move_to_word(ret, i, *str);
	else if (ret == TOUCHE_OPT_X || ret == TOUCHE_OPT_C
	|| ret == TOUCHE_OPT_V)
		ft_cxv(ret, i, str);
	else if (ret == FLECHE_DROITE || ret == FLECHE_GAUCHE)
		ft_move_term(ret, i, *str);
	else if (ret == TOUCHE_OPT_UP || ret == TOUCHE_OPT_DOWN)
		ft_move_to_line(ret, i, *str);
	else if (ft_isprint(ret))
		ft_print(str, ret, i);
	else
		return (0);
	return (1);
}

char			*ft_lecture(t_list_history *head)
{
	char		*str;
	int			ret;
	size_t		i;

	str = NULL;
	i = 0;
	while (42)
	{
		ft_check_end_of_line(str, i);
		ret = 0;
		read(0, &ret, sizeof(int));
		if (ret == TOUCHE_F6 && read(0, &ret, sizeof(int)) > 0)
			continue ;
//		if (ret == TOUCHE_TAB)
//			ret = ft_completion(&str, &i);
		if (ret == TOUCHE_CTRL_C || ret == TOUCHE_CTRL_D)
			exit(1);
		if (ft_lecture_2(ret, &str, &i))
			continue ;
		else if (ret == FLECHE_BAS || ret == FLECHE_HAUT)
		{
			ft_history(&str, ret, &head, &i);
			if (str)
				i = ft_strlen_next(str, i);
			else
				i = 0;
		}
		else if (ret == TOUCHE_HOME || ret == TOUCHE_END)
			ft_home_end(str, ret, &i);
		else if (ft_lecture_3(ret, &str, &i))
			continue ;
		else if (ret == 10)
			break ;
		else if (ft_isascii(ret) == 0)
			ft_read_it(ret, &i, &str);
	}
	if (str)
		ft_putstr(str + i);
	return (str);
}