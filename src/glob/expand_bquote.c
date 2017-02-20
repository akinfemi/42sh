/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:47:53 by wescande          #+#    #+#             */
/*   Updated: 2017/02/20 19:11:11 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static void					expand_all_bquote(t_bquote *me, char *content,
											char *ifs)
{
	char	*content2;

	while ((content2 = ft_strtok(NULL, ifs)))
	{
		ft_ld_pushfront(me->wk, gen_tab(ft_strdup(content),
					calc_expand_esc(me->esc, 0,
						(int[2]){ft_strlen(content), 1}, (int[2]){0, 0}),
					calc_expand_esc(me->esc2, 0,
						(int[2]){ft_strlen(content), 1}, (int[2]){0, 0}), 0));
		content = content2;
	}
	ft_ld_pushfront(me->wk, gen_tab(ft_strjoin(content, me->s2),
				calc_expand_esc(me->esc, 0,
					(int[2]){ft_strlen(content), 1},
					(int[2]){ft_strlen(me->s1) + ft_strlen(me->mid),
					ft_strlen(me->s2)}),
				calc_expand_esc(me->esc2, ft_strlen(me->s1),
					(int[2]){ft_strlen(content), 1},
					(int[2]){ft_strlen(me->s1) + ft_strlen(me->mid),
					ft_strlen(me->s2)}),
				0));
}

static void					init_expand(t_bquote *me, char *content, int esc)
{
	char			*ifs;
	char			*content2;

	ifs = esc ? NULL : ft_getenv(data_singleton()->env, "IFS");
	content = ft_strtok(content, ifs);
	if (!(content2 = ft_strtok(NULL, ifs)))
		ft_ld_pushfront(me->wk, gen_tab(ft_strjoinf(ft_strjoin(me->s1, content),
						me->s2, 1),
					calc_expand_esc(me->esc, ft_strlen(me->s1),
						(int[2]){ft_strlen(content), 1},
						(int[2]){ft_strlen(me->s1) + ft_strlen(me->mid),
						ft_strlen(me->s2)}),
					calc_expand_esc(me->esc2, ft_strlen(me->s1),
						(int[2]){ft_strlen(content), 1},
						(int[2]){ft_strlen(me->s1) + ft_strlen(me->mid),
						ft_strlen(me->s2)}), 0));
	else
	{
		ft_ld_pushfront(me->wk, gen_tab(ft_strjoin(me->s1, content),
					calc_expand_esc(me->esc, ft_strlen(me->s1),
						(int[2]){ft_strlen(content), 1}, (int[2]){0, 0}),
					calc_expand_esc(me->esc2, ft_strlen(me->s1),
						(int[2]){ft_strlen(content), 1}, (int[2]){0, 0}), 0));
		expand_all_bquote(me, content2, ifs);
	}
}

static char					*get_output(char *command)
{
	char	*output;
	int		len;

	output = command_getoutput(command);
	len = ft_strlen(output);
	while (output[--len] == '\n')
		output[len] = '\0';
	return (output);
}

static int					search_bquote(t_bquote *me)
{
	char			*sta;
	char			*content;

	sta = NULL;
	while (*me->str)
	{
		sta = *me->str == '`' && !sta
			&& !is_char_esc(me->esc2, CH(*me->wk)[0], me->str) ? me->str : sta;
		if (sta && *me->str == '`' && me->str != sta
				&& !is_char_esc(me->esc2, CH(*me->wk)[0], me->str))
		{
			me->mid = ft_strsub(sta, 1, me->str - sta - 1);
			me->s1 = ft_strsub(CH(*me->wk)[0], 0, sta - CH(*me->wk)[0]);
			me->s2 = ft_strdup(me->str + 1);
			content = get_output(me->mid);
			init_expand(me, content, is_char_esc(me->esc, CH(*me->wk)[0], sta));
			ft_strdel(&me->mid);
			ft_strdel(&me->s1);
			ft_strdel(&me->s2);
			ft_strdel(&content);
			return (1);
		}
		++me->str;
	}
	return (0);
}

void						expand_bquote(t_glob *gl)
{
	t_ld		*tmp;
	t_bquote	me;
	int			do_it;

	ft_ld_pushfront(&gl->m_pat, gen_tab(gl->pat, gl->esc, gl->esc2, 0));
	me = (t_bquote){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	do_it = 1;
	while ((gl->m_pat = ft_ld_front(gl->m_pat)) && do_it)
	{
		do_it = 0;
		while (gl->m_pat && !do_it)
		{
			me.wk = &gl->m_pat;
			me.esc = UCH(gl->m_pat)[1];
			me.esc2 = UCH(gl->m_pat)[2];
			me.str = CH(gl->m_pat)[0];
			if ((tmp = gl->m_pat) &&
					(do_it = search_bquote(&me)) == 1)
				ft_ld_del(&tmp, &ft_tabdel);
			if (!gl->m_pat->next)
				break ;
			gl->m_pat = gl->m_pat->next;
		}
	}
	ft_ld_reverse(&gl->m_pat);
}
