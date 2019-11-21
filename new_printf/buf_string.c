/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 22:09:21 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 16:39:47 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

void	str_to_buf(char *s, t_vec *buf)
{
	while (*s)
		ft_vpush_back(buf, s++, sizeof(char));
}

size_t	ft_lstrlen(const wchar_t *s)
{
	size_t count;

	count = 0;
	while (*s)
	{
		if (*s <= 127)
			count += 1;
		else if (*s < 2048)
			count += 2;
		else if (*s < 65536)
			count += 3;
		else if (*s < 2097152)
			count += 4;
		s++;
	}
	return (count);
}

/*
**	putstr_buf - puts char string to the ft_printf buffer;
**				puts spaces to the ft_printf buffer to fill out the field width.
*/

void	putstr_buf(char *s, char type, t_pf *sup, t_vec *buf)
{
	size_t	len;

	(!s ? (s = "(null)") : 0);
	len = ft_strlen(s);
	if (sup->preci >= 0)
	{
		sup->preci = (sup->preci > len) ? len : sup->preci;
		len = sup->preci;
	}
	sup->width = sup->width - ((sup->width > len) ? (len - 1) : sup->width);
	put_width(buf, sup, 'R', ' ');
	if (sup->preci < 0)
		str_to_buf(s, buf);
	else
		while (sup->preci)
		{
			ft_vpush_back(buf, s++, sizeof(char));
			sup->preci--;
		}
	put_width(buf, sup, 'L', ' ');
}

/*
**	putlstr_buf - puts wchar string to the ft_printf buffer;
**				puts spaces to the ft_printf buffer to fill out the field width.
*/

void	putlstr_buf(wchar_t *s, char type, t_pf *sup, t_vec *buf)
{
	size_t	len;

	(!s ? (s = L"(null)") : 0);
	len = ft_lstrlen(s);
	sup->width = sup->width - ((sup->width > len) ? (len - 1) : sup->width);
	put_width(buf, sup, 'R', ' ');
	while (*s)
		buf_wchar(*(s++), buf);
	put_width(buf, sup, 'L', ' ');
}
