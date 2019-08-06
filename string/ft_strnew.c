/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:29:54 by chermist          #+#    #+#             */
/*   Updated: 2018/12/04 22:58:08 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	size_max;

	size_max = -1;
	if ((size_max == size) || !(str = malloc(size + 1)))
		return (NULL);
	ft_memset(str, 0, size + 1);
	return (str);
}
