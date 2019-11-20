/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 01:40:51 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 01:10:22 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

void	putnbr_buf(t_pf *sup, t_vec *buf, t_vec *nbuf)
{
	size_t	len;
	char	delim;
	int		i;
	int		flag;

	flag = 1;
	i = 0;
	ft_vpush_back(nbuf, "\0", sizeof(char));
	len = nbuf->size - 1 + (sup->plus == '+' ? 1 : 0);
	if (*(char*)ft_vat(nbuf, 0) == '-')
		i = 1;
	if (len < sup->preci || (i && (len - 1) < sup->preci))
	{
		if (i)
			ft_vpush_back(buf, "-", sizeof(char));
		else if (sup->plus == '+')
		{
			ft_vpush_back(buf, "+", sizeof(char));
			flag = 0;
		}
		sup->preci -= (len < sup->preci ? len : len - 1);
		if (!flag)
			sup->preci++;
		while (sup->preci--)
			ft_vpush_back(buf, "0", sizeof(char));
	}
	else if(i)
		ft_vpush_back(buf, "-", sizeof(char));

	if (sup->width > 1)
		sup->width = sup->width - ((sup->width > len) ? (len - 1) : sup->width);
	put_width(buf, sup, 'R');
	if (sup->plus == '+' && flag)
		ft_vpush_back(buf, "+", sizeof(char));
	while (i < len)
		ft_vpush_back(buf, ft_vat(nbuf, i++), sizeof(char));
//	str_to_buf(nbuf->data, buf);
	put_width(buf, sup, 'L');
}
