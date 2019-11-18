/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:29:44 by chermist          #+#    #+#             */
/*   Updated: 2019/11/18 17:35:50 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_move(char **str)
{
	int					sign;
	int					len;
	unsigned long long	num;

	num = 0;
	sign = 0;
	if (str && *str)
	{
		while (!(len = 0) && ft_isspace(**str))
			(*str)++;
		sign = (**str == '-') ? -1 : 1;
		(**str == '-' || **str == '+') ? (*str)++ : *str;
		while (**str == '0')
			(*str)++;
		while (ft_isdigit(**str) && (++len < 21))
			num = num * 10 + (*((*str)++) - '0');
		if (sign > 0 && (len > 19 || num > 9223372036854775807))
			return (-1);
		if (sign < 0 && (len > 19 || num > 9223372036854775808ULL))
			return (0);
	}
	return (sign * num);
}
