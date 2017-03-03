/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_foreground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:58:36 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 18:38:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		put_job_in_foreground(t_job *j, int cont)
{
	t_jobc	*jobc;

	jobc = &data_singleton()->jobc;
	tcsetpgrp(STDIN, j->pgid);
	tcsetattr(STDIN, TCSADRAIN, &jobc->shell_tmodes);

	if (cont)
	{
		tcsetattr(STDIN, TCSADRAIN, &j->tmodes);
		if (kill(-j->pgid, SIGCONT) < 0)
			DG("kill(SIGCONT) failed");
	}
	DG("before wait");
	job_wait(j->id);
	DG("after wait");
	job_remove(j->id);

	tcsetpgrp(STDIN, jobc->shell_pgid);

	tcgetattr(STDIN, &j->tmodes);
	tcsetattr(STDIN, TCSADRAIN, &jobc->shell_tmodes);
	return (0);
}
