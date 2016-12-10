/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:41:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/10 10:24:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITING_H
# define LINE_EDITING_H

# include "ft_readline.h"
# include "minishell.h"

typedef struct s_data	t_data;

t_data					**data_singleton(void);
int						ft_interactive_sh(t_data *data);

#endif
