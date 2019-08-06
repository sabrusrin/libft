/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:53:12 by chermist          #+#    #+#             */
/*   Updated: 2018/12/03 20:53:59 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		tmp;
	char	*str;

	len = 1;
	tmp = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (tmp /= 10)
		len++;
	if (n < 0)
	{
		len += ++tmp;
		n *= -1;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (tmp)
		str[0] = '-';
	return (str);
}
