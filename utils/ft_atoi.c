/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:30:20 by chermist          #+#    #+#             */
/*   Updated: 2018/12/08 23:51:20 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	int					len;
	unsigned long long	num;

	num = 0;
	while (!(len = 0) && ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? str++ : str;
	while (*str == '0')
		str++;
	while (ft_isdigit(*str) && (++len < 21))
		num = num * 10 + (*str++ - '0');
	if (sign > 0 && (len > 19 || num > 9223372036854775807))
		return (-1);
	if (sign < 0 && (len > 19 || num > 9223372036854775808ULL))
		return (0);
	return (sign * num);
}
