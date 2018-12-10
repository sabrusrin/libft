/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:24:14 by chermist          #+#    #+#             */
/*   Updated: 2018/12/07 23:21:49 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!len)
		return ((char*)s);
	while ((s[len - 1] == '\n' || s[len - 1] == '\t' || s[len - 1] == ' ')
			&& len)
		len--;
	i = 0;
	while ((s[i] == '\n' || s[i] == '\t' || s[i] == ' ') && len)
		i++;
	return (ft_strsub(s, i, len - i));
}
