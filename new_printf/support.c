/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:38:04 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 16:39:02 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

int	ft_wildcard(va_list ap, char **str, t_pf *sup)
{
	int	arg;

	arg = 0;
	if (str && *str && **str == '*' && (*str)++)
	{
		arg = va_arg(ap, int);
		if (arg < 0 && *(*str - 2) != '.' && (arg *= -1))
			sup->minus = '-';
		return (arg);
	}
	return (0);
}

void	put_width(t_vec *buf, t_pf *sup, char pos, char delim)
{
	if (sup->width > 1 && sup->minus != '-' && pos == 'R')
		while (--sup->width)
			ft_vpush_back(buf, &delim, sizeof(char));
	else if (sup->width > 1 && sup->minus == '-' && pos == 'L')
		while (--sup->width)
			ft_vpush_back(buf, " ", sizeof(char));
}
