/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:25:55 by chermist          #+#    #+#             */
/*   Updated: 2018/12/13 00:57:57 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cp;
	char	*pcp;

	len = ft_strlen(s1);
	if (!(cp = malloc(len + 1)))
		return (NULL);
	pcp = cp;
	while (len--)
		*cp++ = *s1++;
	*(cp) = 0;
	return (pcp);
}
