/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:25 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 15:43:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*addr;
	size_t	i;

	addr = ft_malloc(size);
	if (addr == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		((char *)addr)[i] = 0;
	return (addr);
}
