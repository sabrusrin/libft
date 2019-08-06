/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:25:02 by chermist          #+#    #+#             */
/*   Updated: 2018/11/30 11:51:16 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;

	if (n)
	{
		ps = (unsigned char*)s;
		while (n--)
			if (*ps++ == (unsigned char)c)
				return ((void*)(ps - 1));
	}
	return (NULL);
}
