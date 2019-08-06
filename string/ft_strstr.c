/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:28:56 by chermist          #+#    #+#             */
/*   Updated: 2019/05/27 20:41:39 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	hi;
	size_t	ni;
	size_t	len;

	hi = 0;
	ni = 0;
	len = ft_strlen(needle);
	if (!len)
		return ((char*)haystack);
	while (haystack[hi])
	{
		ni = 0;
		while (needle[ni] == haystack[ni + hi])
		{
			if (ni++ == len - 1)
				return ((char*)haystack + hi);
		}
		hi++;
	}
	return (NULL);
}
