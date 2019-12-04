/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:31:37 by chermist          #+#    #+#             */
/*   Updated: 2019/12/05 00:32:03 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_vec	*itoa_buf(long long n, t_vec *nbuf)
{
	char	num;

	num = 0;
	if (n == INT64_MIN)
	{
		str_to_buf("-9223372036854775808", nbuf);
		return (nbuf);
	}
	if (n < 0)
	{
		ft_vpush_back(nbuf, "-", sizeof(char));
		n *= -1;
	}
	if (n < 10)
	{
		num = n + '0';
		ft_vpush_back(nbuf, &num, sizeof(char));
		return (nbuf);
	}
	itoa_buf(n / 10, nbuf);
	num = (n % 10) + '0';
	ft_vpush_back(nbuf, &num, sizeof(char));
	return (nbuf);
}

t_vec	*uitoa_buf(uintmax_t n, t_vec *nbuf)
{
	char	num;

	num = 0;
	if (n < 10)
	{
		num = n + '0';
		ft_vpush_back(nbuf, &num, sizeof(char));
		return (nbuf);
	}
	itoa_buf(n / 10, nbuf);
	num = (n % 10) + '0';
	ft_vpush_back(nbuf, &num, sizeof(char));
	return (nbuf);
}

t_vec	*itoa_base_buf(uintmax_t num, t_vec *nbuf, t_pf *sup, char type)
{
	char	*base_chars;
	char	buff[50];
	char	*fill;
	int		base;

	fill = &buff[49];
	*fill = '\0';
	sup->num = num;
	base_chars = (type != 'X') ? "0123456789abcdef" : "0123456789ABCDEF";
	base = 16;
	if (type == 'o' || type == 'O')
		base = 8;
	if (type == 'p')
		sup->flags |= HASH;
	if (sup->flags & HASH && (type == 'o' || type == 'O') &&\
										(sup->preci == -2 || sup->preci == 0))
		;
	else if (type != 'p' && sup->flags & HASH && !num)
		sup->flags ^= HASH;
	if (num == 0)
		*--fill = base_chars[num];
	while (num != 0 && (*--fill = base_chars[num % base]))
		num /= base;
	str_to_buf(fill, nbuf);
	return (nbuf);
}
