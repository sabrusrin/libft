/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:40:51 by chermist          #+#    #+#             */
/*   Updated: 2019/11/23 02:30:31 by chermist         ###   ########.fr       */
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
