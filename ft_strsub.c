/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:40:05 by chermist          #+#    #+#             */
/*   Updated: 2018/12/05 15:16:31 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		i;

	i = 0;
	if (!s || !(subs = ft_strnew(len)) || (start > ft_strlen(s)))
		return (NULL);
	while (start--)
		s++;
	ft_strncpy(subs, s, len);
	return (subs);
}
