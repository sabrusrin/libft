/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:40:51 by chermist          #+#    #+#             */
/*   Updated: 2019/11/23 19:45:15 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	padding functions put padding if needed, respecting all the other flags
*/

void	zero_padding(t_pf *sup, t_vec *buf, int wlen, int i)
{
	if (sup->plus == '+' || i)
		ft_vpush_back(buf, &sup->sign, sizeof(char));
	sup->width -= ((sup->width > (size_t)wlen) ? wlen : sup->width);
	if (sup->space == ' ' && sup->sign != '-' && sup->plus != '+')
		ft_vpush_back(buf, &sup->space, sizeof(char));
	put_full_width(buf, sup, 'R', '0');
}

void	space_padding(t_pf *sup, t_vec *buf, int wlen, int i)
{
	sup->width -= ((sup->width > (size_t)wlen) ? wlen : sup->width);
	if (sup->space == ' ' && sup->sign != '-' &&\
														sup->plus != '+')
		ft_vpush_back(buf, &sup->space, sizeof(char));
	put_full_width(buf, sup, 'R', ' ');
	if (sup->plus == '+' || i)
		ft_vpush_back(buf, &sup->sign, sizeof(char));
}

/*
**	precision_nbr - puts precision zeros to the buffer,
**	respecting all the other flags
*/

void	precision_nbr(t_pf *sup, t_vec *buf, t_vec *nbuf, int len)
{
	int	i;

	i = 0;
	if (*(char*)ft_vat(nbuf, 0) == '-')
		i = 1;
	sup->preci -= !i || (!i && sup->plus == '+') ? nbuf->size : nbuf->size - 1;
	len += sup->preci;
	sup->width -= ((sup->width > (size_t)len) ? len : sup->width);
	if (sup->space == ' ' && sup->sign != '-' && sup->plus != '+')
		ft_vpush_back(buf, &sup->space, sizeof(char));
	put_full_width(buf, sup, 'R', ' ');
	if (sup->sign == '-')
		ft_vpush_back(buf, "-", sizeof(char));
	else if (sup->plus == '+')
	{
		ft_vpush_back(buf, "+", sizeof(char));
		i = 1;
	}
	while (sup->preci--)
		ft_vpush_back(buf, "0", sizeof(char));
}

/*
**	putnbr_buf - considers the padding, precision and flags then puts
**	the number to the ft_printf buffer
*/

void	putnbr_buf(t_pf *sup, t_vec *buf, t_vec *nbuf)
{
	int	len;
	int	wlen;
	int	i;

	i = 0;
	sup->sign = (*(char*)ft_vat(nbuf, 0) != '-') ? '+' : '-';
	len = nbuf->size;
	if (*(char*)ft_vat(nbuf, 0) == '-')
		i = 1;
	wlen = len + ((!i && (sup->plus == '+' || sup->space == ' ')) ? 1 : 0);
	if (sup->preci > len || (i && sup->preci > (len - 1)))
		precision_nbr(sup, buf, nbuf, wlen);
	else if (sup->zero == '0' && sup->minus != '-' && sup->preci == -1)
		zero_padding(sup, buf, wlen, i);
	else
		space_padding(sup, buf, wlen, i);
	while (i < len)
		ft_vpush_back(buf, ft_vat(nbuf, i++), sizeof(char));
	put_full_width(buf, sup, 'L', ' ');
}

void	putbase_buf(t_pf *sup, t_vec *buf, char type, t_vec *nbuf)
{
	char	*hash;
	int		len;
	int		wlen;
	int		n;
	int		i;

	n = 0;
	i = 0;
	len = nbuf->size;
	sup->preci -= (sup->preci > 0 && sup->preci > len) ? len : sup->preci;
	wlen = len + sup->preci;
	if (sup->hash == '#')
	{
		if (type == 'x' || type == 'X')
		{
			hash = (type == 'x' ? "0x" : "0X");
			n = 2;
		}
		else if (type == 'o' || type == 'O')
		{
			hash = "0";
			n = 1;
		}
		else if (type == 'p')
		{
			hash = "0x";
			n = 2;
		}
	}
	sup->width -= (sup->width > (size_t)wlen + n) ? wlen + n : sup->width;
	if (sup->preci > 0)
	{
		put_full_width(buf, sup, 'R', ' ');
		while (n--)
			ft_vpush_back(buf, hash++, sizeof(char));
		while (sup->preci--)
			ft_vpush_back(buf, "0", sizeof(char));
	}
	else if (sup->width > 0 && sup->zero == '0' && sup->minus == 0)
	{
		while (n--)
			ft_vpush_back(buf, hash++, sizeof(char));
		put_full_width(buf, sup, 'R', '0');
	}
	else
	{
		while (n--)
			ft_vpush_back(buf, hash++, sizeof(char));
		put_full_width(buf, sup, 'R', ' ');
	}
	while (i < len)
		ft_vpush_back(buf, ft_vat(nbuf, i++), sizeof(char));
	put_full_width(buf, sup, 'L', ' ');
}
