/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:52:24 by chermist          #+#    #+#             */
/*   Updated: 2019/12/03 22:59:06 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_bytes(wint_t c, t_pf *sup)
{
	size_t b;

	b = 0;
	if (c <= 127)
		return (sup->width);
	else if (c < 2048)
		return (sup->width > 0 ? sup->width - 1 : 0);
	else if (c < 65536)
		return (sup->width > 1 ? sup->width - 2 : 0);
	else if (c < 2097152)
		return (sup->width > 2 ? sup->width - 3 : 0);
	return (-1);
}

int		buf_more_bytes_wchar(wchar_t c, t_vec *buf, int bytes)
{
	wchar_t a;

	a = 0;
	if (c < 65536 && (bytes == 0 || bytes == 3))
	{
		a = ((c >> 12) | 0xE0);
		ft_vpush_back(buf, &a, sizeof(char));
		a = (((c >> 6) & 63) | 0x80);
		ft_vpush_back(buf, &a, sizeof(char));
		a = ((c & 63) | 0x80);
		ft_vpush_back(buf, &a, sizeof(char));
		return (3);
	}
	else if (c < 2097152 && (bytes == 0 || bytes == 4))
	{
		a = ((c >> 18) | 0xF0);
		ft_vpush_back(buf, &a, sizeof(char));
		a = (((c >> 12) & 63) | 0x80);
		ft_vpush_back(buf, &a, sizeof(char));
		a = (((c >> 6) & 63) | 0x80);
		ft_vpush_back(buf, &a, sizeof(char));
		a = ((c & 63) | 0x80);
		ft_vpush_back(buf, &a, sizeof(char));
	}
	return ((c < 2097152) ? 4 : -1);
}

int		buf_wchar(wchar_t c, t_vec *buf, int bytes)
{
	wchar_t a;

	a = 0;
	if (c <= 127 && (bytes == 0 || bytes == 1))
	{
		ft_vpush_back(buf, &c, sizeof(char));
		return (1);
	}
	else if (c < 2048 && (bytes == 0 || bytes == 2))
	{
		a = ((c >> 6) | 0xC0);
		ft_vpush_back(buf, &a, sizeof(char));
		a = ((c & 63) | 0x80);
		ft_vpush_back(buf, &a, sizeof(char));
		return (2);
	}
	return (buf_more_bytes_wchar(c, buf, bytes));
}

/*
**	putchar_buf - puts char or wchar to the ft_printf buffer;
**				puts spaces to the ft_printf buffer to fill out the field width.
*/

void	putchar_buf(wchar_t c, char type, t_pf *sup, t_vec *buf)
{
	unsigned char	a;
	wchar_t			b;

	a = (unsigned char)c;
	b = (wchar_t)c;
	if ((sup->width = check_bytes(c, sup)) == -1)
	{
		sup->kill = TRUE;
		return ;
	}
	put_width(buf, sup, 'R', sup->pad_char);
	if (type == 'c' && sup->length == 0)
		ft_vpush_back(buf, &a, sizeof(char));
	else if ((type == 'c' && sup->length == 4) || (type == 'C' && !sup->length))
		buf_wchar(b, buf, 0);
	put_width(buf, sup, 'L', ' ');
}
