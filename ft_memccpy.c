/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:23:30 by chermist          #+#    #+#             */
/*   Updated: 2018/11/30 11:53:10 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	if (n)
	{
		pd = dst;
		ps = src;
		while (n--)
		{
			if ((*pd++ = *ps++) == (unsigned char)c)
				return (pd);
		}
	}
	return (NULL);
}
