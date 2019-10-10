/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_ft_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:28:33 by chermist          #+#    #+#             */
/*   Updated: 2019/10/11 00:13:04 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	more_bytes_putchar(int c)
{
	int a;

	a = 0;
	if (c < 65536)
	{
		a = ((c >> 12) | 0xE0);
		write(1, &a, 1);
		a = (((c >> 6) & 63) | 0x80);
		write(1, &a, 1);
		a = ((c & 63) | 0x80);
		write(1, &a, 1);
		return (3);
	}
	else if (c < 2097152)
	{
		a = ((c >> 18) | 0xF0);
		write(1, &a, 1);
		a = (((c >> 12) & 63) | 0x80);
		write(1, &a, 1);
		a = (((c >> 6) & 63) | 0x80);
		write(1, &a, 1);
		a = ((c & 63) | 0x80);
		write(1, &a, 1);
	}
	return ((c < 2097152) ? 4 : -1);
}

int	l_ft_putchar(int c)
{
	int a;

	a = 0;
	if (c <= 127)
	{
		write(1, &c, 1);
		return (1);
	}
	else if (c < 2048)
	{
		a = ((c >> 6) | 0xC0);
		write(1, &a, 1);
		a = ((c & 63) | 0x80);
		write(1, &a, 1);
		return (2);
	}
	return (more_bytes_putchar(c));
}
