/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 22:09:21 by chermist          #+#    #+#             */
/*   Updated: 2019/11/22 17:28:36 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		wchar_bytes(wint_t c)
{
	if (c <= 127)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else if (c < 2097152)
		return (4);
	return (-1);
}

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
	type = 0;
	if (sup->preci >= 0)
	{
		sup->preci = ((size_t)sup->preci > len) ? len : sup->preci;
		len = sup->preci;
	}
	sup->width -= ((sup->width > len) ? len : sup->width);
	put_full_width(buf, sup, 'R', ' ');
	if (sup->preci < 0)
		str_to_buf(s, buf);
	else
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

/* size_t	check_wlen(wchar_t *s, t_pf *sup)
{
	int	tmp;
	int	printable;
	int	count;

	tmp = sup->preci;
	printable = 0;
	while (tmp > 0)
	{
		count = wchar_bytes(*s);
		if (tmp > 4)
		{
			printable += count;
			tmp -= count;
		}
		else
		{
			printable += (tmp > count ? count : tmp);
			tmp -= (tmp > count ? count : tmp);
		}
		s++;
	}
	ft_putchar('|');
	ft_putnbr(sup->preci);
	ft_putchar('|');
	ft_putnbr(printable);
	ft_putchar('|');
	ft_putchar('\n');
	return (printable);
} */

void	putlstr_buf(wchar_t *s, char type, t_pf *sup, t_vec *buf)
{
	size_t	len;

	(!s ? (s = L"(null)") : 0);
	len = ft_lstrlen(s);
/* 	ft_putchar('|');
	ft_putnbr(len);
	ft_putchar('\n'); */
	if (type == 's' && sup->preci >= 0)
	{
		sup->preci = ((size_t)sup->preci > len) ? len : sup->preci;
		len = sup->preci;
	}
	sup->width -= (sup->width > len) ? len : sup->width;
/* 	ft_putchar('|');
	ft_putnbr(len);
	ft_putchar('|');
	ft_putnbr(sup->width);
	ft_putchar('\n'); */
	put_full_width(buf, sup, 'R', ' ');
	if (sup->preci < 0)
		while (*s)
			buf_wchar(*(s++), buf, 0);
	else
		while (sup->preci > 0)
		{
			if (sup->preci > 4)
				sup->preci -= buf_wchar(*s, buf, 0);
			else
				sup->preci -= buf_wchar(*s, buf,\
				(sup->preci > wchar_bytes(*s) ? wchar_bytes(*s) : sup->preci));
			s++;
		}
	put_full_width(buf, sup, 'L', ' ');
}
