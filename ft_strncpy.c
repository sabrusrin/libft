/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:26:48 by chermist          #+#    #+#             */
/*   Updated: 2018/12/05 14:53:50 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t lsrc;

	i = 0;
	lsrc = 0;
	lsrc = ft_strlen(src);
	while (i < len)
	{
		if (i < lsrc)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
