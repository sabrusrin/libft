/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:40:51 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 18:39:39 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

void	precinbr(t_pf *sup, t_vec *buf, t_vec *nbuf, int len)
{
	int	i;

	i = 0;
	if (*(char*)ft_vat(nbuf, 0) == '-' || sup->plus == '+')
		i = 1;
	sup->preci -= ((len < sup->preci && !i) ? len : len - 1);
	len += sup->preci;
	if (sup->width > len)
	{
		sup->width -= len - 1;
		put_width(buf, sup, 'R', ' ');
	}
	else if (sup->plus != '+' && sup->space == ' ')
		ft_vpush_back(buf, " ", sizeof(char));
	if (sup->sign == '-')
		ft_vpush_back(buf, "-", sizeof(char));
	else if (sup->plus == '+')
		ft_vpush_back(buf, "+", sizeof(char));
	while (sup->preci--)
		ft_vpush_back(buf, "0", sizeof(char));
}

void	putnbr_buf(t_pf *sup, t_vec *buf, t_vec *nbuf)
{
	int	len;
	int	wlen;
	int	i;

	i = 0;
	sup->sign = (*(char*)ft_vat(nbuf, 0) != '-') ? '+' : '-';
	len = (int)nbuf->size;
	if (*(char*)ft_vat(nbuf, 0) == '-')
		i = 1;
	wlen = len + ((sup->plus == '+' && !i) ? 1 : 0);
	if (sup->preci > len || (i && sup->preci > (len - 1)))
		precinbr(sup, buf, nbuf, wlen);
	else if (sup->zero == '0' && sup->minus != '-')
	{
		if (sup->plus == '+')
			ft_vpush_back(buf, &sup->sign, sizeof(char));
		sup->width -= ((sup->width > wlen) ? (wlen - 1) : sup->width);
		put_width(buf, sup, 'R', '0');
	}
	else if (sup->width > len)
	{
		sup->width -= ((sup->width > wlen) ? (wlen - 1) : sup->width);
		put_width(buf, sup, 'R', ' ');
		if (sup->plus == '+' && sup->sign == '+')
			ft_vpush_back(buf, "+", sizeof(char));
	}
	else if (sup->plus != '+' && sup->space == ' ')
		ft_vpush_back(buf, " ", sizeof(char));
	while (i < len)
		ft_vpush_back(buf, ft_vat(nbuf, i++), sizeof(char));
	put_width(buf, sup, 'L', ' ');
}
