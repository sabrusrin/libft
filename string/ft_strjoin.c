/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:10:55 by chermist          #+#    #+#             */
/*   Updated: 2018/12/02 22:58:14 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*catstr;

	if (!s1 || !s2 || !(catstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	return (ft_strcat(ft_strcat(catstr, s1), s2));
}
