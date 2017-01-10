/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:03:29 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/08 13:24:53 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int	 put_job_in_background(t_job *job, int cont)
{
	/* Send the job a continue signal, if necessary.  */
	if (cont)
		if (kill (-job->pgid, SIGCONT) < 0)
			perror ("kill (SIGCONT)");
	return (0);
}