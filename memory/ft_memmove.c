/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:23:55 by chermist          #+#    #+#             */
/*   Updated: 2018/12/13 00:12:22 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pd;
	char	*ps;

	ps = (char*)src;
	if (ps < (pd = (char*)dst))
		while ((int)(--len) >= 0)
			pd[len] = ps[len];
	else
		while (len--)
			*pd++ = *ps++;
	return (dst);
}
