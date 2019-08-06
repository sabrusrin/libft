/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:59:19 by chermist          #+#    #+#             */
/*   Updated: 2018/12/02 20:30:56 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fstr;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(fstr = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		fstr[i] = f(i, s[i]);
		i++;
	}
	return (fstr);
}
