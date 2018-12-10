/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:23:55 by chermist          #+#    #+#             */
/*   Updated: 2018/12/08 18:22:28 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pd;
	char	*ps;
	size_t	i;

	i = -1;
	pd = (char*)dst;
	ps = (char*)src;
	if (ps < pd)
		while ((int)(--len) >= 0)
			pd[len] = ps[len];
	else
		while (++i < len)
			pd[i] = ps[i];
	return (dst);
}
