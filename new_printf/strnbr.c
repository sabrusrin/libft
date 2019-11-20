/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:31:37 by chermist          #+#    #+#             */
/*   Updated: 2019/11/20 23:51:26 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

t_vec	*strnbr(int n, t_vec *nbuf)
{
	char	num;

	if (n == INT32_MIN)
	{
		str_to_buf("-2147483648", nbuf);
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
	strnbr(n / 10, nbuf);
	num = (n % 10) + '0';
	ft_vpush_back(nbuf, &num, sizeof(char));
	return (nbuf);
}

t_vec	*strnbr_h(short n, t_vec *nbuf)
{
	int	num;

	if (n == INT16_MIN)
	{
		str_to_buf("-32768", nbuf);
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
		ft_vpush_back(nbuf, "\0", sizeof(char));
		return (nbuf);
	}
	strnbr_h(n / 10, nbuf);
	num = (n % 10) + '0';
	ft_vpush_back(nbuf, &num, sizeof(char));
	return (nbuf);
}

t_vec	*strnbr_hh(signed char n, t_vec *nbuf)
{
	int	num;

	if (n == INT8_MIN)
	{
		str_to_buf("-128", nbuf);
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
		ft_vpush_back(nbuf, "\0", sizeof(char));
		return (nbuf);
	}
	strnbr_hh(n / 10, nbuf);
	num = (n % 10) + '0';
	ft_vpush_back(nbuf, &num, sizeof(char));
	return (nbuf);
}

t_vec	*strnbr_ll(long long n, t_vec *nbuf)
{
	int	num;

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
		ft_vpush_back(nbuf, "\0", sizeof(char));
		return (nbuf);
	}
	strnbr_ll(n / 10, nbuf);
	num = (n % 10) + '0';
	ft_vpush_back(nbuf, &num, sizeof(char));
	return (nbuf);
}
