/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:29:15 by chermist          #+#    #+#             */
/*   Updated: 2018/12/07 20:52:40 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstck, const char *ndl, size_t len)
{
	size_t	hi;
	size_t	ni;
	size_t	szn;

	hi = 0;
	ni = 0;
	szn = ft_strlen(ndl);
	if (!szn)
		return ((char*)hstck);
	while (len && hstck[hi])
	{
		ni = 0;
		if (len < szn)
			return (NULL);
		while ((ndl[ni] == hstck[ni + hi]))
		{
			if (ni++ == szn - 1)
				return ((char*)hstck + hi);
		}
		len--;
		hi++;
	}
	return (NULL);
}
