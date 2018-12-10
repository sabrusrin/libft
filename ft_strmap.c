/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:39:45 by rustamsabit       #+#    #+#             */
/*   Updated: 2018/12/02 19:54:39 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		fstr[i] = f(s[i]);
		i++;
	}
	return (fstr);
}
