/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:25:55 by chermist          #+#    #+#             */
/*   Updated: 2018/11/30 16:39:13 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*cp;

	i = 0;
	len = 0;
	len = ft_strlen(s1);
	if (!(cp = malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = 0;
	return (cp);
}
