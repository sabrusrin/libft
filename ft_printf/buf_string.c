/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 22:09:21 by chermist          #+#    #+#             */
/*   Updated: 2019/12/05 00:18:38 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	putstr_buf - puts char string to the ft_printf buffer;
**				puts spaces to the ft_printf buffer to fill out the field width.
*/

void	putstr_buf(char *s, char type, t_pf *sup, t_vec *buf)
{
	int	len;

	(!s ? (s = "(null)") : 0);
	len = (sup->preci == 0 || sup->preci == -2) ? 0 : ft_strlen(s);
	type = 0;
	if (sup->preci >= 0)
	{
		sup->preci = (sup->preci > len) ? len : sup->preci;
		len = sup->preci;
	}
	sup->width -= ((sup->width > len) ? len : sup->width);
	put_full_width(buf, sup, 'R', sup->pad_char);
	if (sup->preci < 0 && sup->preci != -2)
		str_to_buf(s, buf);
	else if (sup->preci != 0 && sup->preci != -2)
		while (sup->preci)
		{
			ft_vpush_back(buf, s++, sizeof(char));
			sup->preci--;
		}
	put_full_width(buf, sup, 'L', ' ');
}

/*
**	putlstr_buf - puts wchar string to the ft_printf buffer;
**				puts spaces to the ft_printf buffer to fill out the field width.
*/

void	putlstr_buf(wchar_t *s, char type, t_pf *sup, t_vec *buf)
{
	int	len;

	(!s ? (s = L"(null)") : 0);
	len = (sup->preci == 0 || sup->preci == -2) ? 0 : ft_lstrlen(s);
	if (type == 's' && sup->preci != -1 && sup->preci < len)
		len = precision_len(s, sup);
	else
		sup->preci = -1;
	sup->width -= (sup->width > len) ? len : sup->width;
	put_full_width(buf, sup, 'R', sup->pad_char);
	wstring_buf(s, sup, buf);
	put_full_width(buf, sup, 'L', ' ');
}

void	wstring_buf(wchar_t *s, t_pf *sup, t_vec *buf)
{
	int	bytes;

	bytes = 0;
	if (sup->preci < 0)
		while (*s)
			buf_wchar(*(s++), buf, 0);
	else
		while (sup->preci > 0)
		{
			if (sup->preci > 4)
				sup->preci -= buf_wchar(*s, buf, 0);
			else
			{
				bytes = wchar_bytes(*s);
				sup->preci -= buf_wchar(*s, buf,\
				(sup->preci > bytes ? bytes : sup->preci));
			}
			s++;
		}
}
