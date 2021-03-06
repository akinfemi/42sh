/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_find_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:31:21 by alao              #+#    #+#             */
/*   Updated: 2017/03/23 19:08:08 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** If the parsing for local file fail. The function is called to check if the
** match is actually a folder. If so, the command is updated with a trailing
** slash (/) using c_updater.
**     Exemple:       cd folder[tab]      to      cd folder/
** Returning 1 if success (trigger an update) or 0.
*/

int			c_exclusion_folder(t_comp *c)
{
	DIR		*rep;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(c->cpath, c->match);
	tmp2 = NULL;
	if ((rep = opendir(tmp)) && (!closedir(rep)))
	{
		tmp ? ft_memdel((void *)&tmp) : (0);
		if (c->rcmd[ft_strlen(c->rcmd) - 1] == '/'
		|| c->rcmd[ft_strlen(c->rcmd) - 1] == '.')
		{
			c_clear(data_singleton());
			return (0);
		}
		tmp2 = ft_strjoin(c->match, "/");
		c_updater(c, tmp2);
		tmp2 ? ft_memdel((void *)&tmp2) : (0);
		return (1);
	}
	tmp ? ft_memdel((void *)&tmp) : (0);
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (0);
}

/*
** Clear the binary from c->rcmd ans save the result in c->match. Return the
** path part of it if exist or NULL.
*/

static char	*c_slicer(t_comp *c)
{
	char	*tmp;
	char	*rt;
	int		i;

	i = 0;
	tmp = NULL;
	rt = NULL;
	while (c->rcmd[i] && c->rcmd[i] != ' ')
		i++;
	c->rcmd[i] == ' ' ? i++ : (0);
	if (i == (int)ft_strlen(c->rcmd))
		return (NULL);
	tmp = ft_strsub(c->rcmd, i, ft_strlen(c->rcmd) - i);
	i = ft_strlen(tmp) - 1;
	while (i > 0 && tmp[i] && tmp[i] != '/')
		i--;
	tmp[i] == '/' ? i++ : (0);
	rt = (i == (int)ft_strlen(tmp) - 1) ? NULL : ft_strsub(tmp, 0, i);
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (rt);
}

/*
** Files searching
*/

int			c_seek_files(t_data *s, t_comp *c, char *current_word)
{
	char	*path;

	(void)s;
	if (c->rcmd[0] == '.')
	{
		c->cpath = ft_strdup("./");
		c->match = ft_strdup(current_word);
	}
	if (c->cpath == NULL)
	{
		path = c_slicer(c);
		c->match = ft_strdup(current_word);
		c->cpath = path_solver(c, path, NULL);
		path ? ft_memdel((void *)&path) : (0);
	}
	c_parser(c, c->cpath, c->match);
	if (c->lst == NULL && c->isrematch == 0)
		c_exclusion_folder(c);
	else if ((c->lst && (c->lst == c->lst->next)) && c->isrematch == 0)
	{
		if (c->match && ft_strequ(c->match, c->lst->name))
			c_exclusion_folder(c);
	}
	c_lst_id(data_singleton()->comp);
	return (0);
}
