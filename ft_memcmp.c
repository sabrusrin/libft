/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:25:17 by chermist          #+#    #+#             */
/*   Updated: 2018/11/30 12:37:00 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char ps1;
	unsigned char ps2;

	while (n--)
	{
		ps1 = *(unsigned char*)s1;
		ps2 = *(unsigned char*)s2;
		if (ps1 != ps2)
			return (ps1 - ps2);
		s1++;
		s2++;
	}
	return (0);
}
