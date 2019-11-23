/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:31:37 by chermist          #+#    #+#             */
/*   Updated: 2019/11/23 13:49:07 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* void	itoa_base_buf(intmax_t num, t_vec * nbuf)
{

} */

t_vec	*strnbr_buf(long long n, t_vec *nbuf)
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
	strnbr_buf(n / 10, nbuf);
	num = (n % 10) + '0';
	ft_vpush_back(nbuf, &num, sizeof(char));
	return (nbuf);
}

t_vec	*strunbr_buf(unsigned long long n, t_vec *nbuf)
{
	char	num;

	num = 0;
	if (n < 10)
	{
		num = n	+ '0';
		ft_vpush_back(nbuf, &num, sizeof(char));
		return (nbuf);
	}
	strnbr_buf(n / 10, nbuf);
	num = (n % 10) + '0';
	ft_vpush_back(nbuf, &num, sizeof(char));
	return (nbuf);
}