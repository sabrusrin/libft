/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:28:36 by chermist          #+#    #+#             */
/*   Updated: 2018/11/28 23:34:27 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pc;

	pc = (char*)s + ft_strlen(s);
	while (*pc != c)
	{
		if (pc == s)
			return (NULL);
		pc--;
	}
	return (pc);
}
