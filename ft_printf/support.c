/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:38:04 by chermist          #+#    #+#             */
/*   Updated: 2019/12/04 18:26:06 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wildcard(va_list ap, char **str, t_pf *sup)
{
	int	arg;

	arg = 0;
	if (str && *str && **str == '*' && (*str)++)
	{
		arg = va_arg(ap, int);
		if (arg < 0 && *(*str - 2) != '.' && (arg *= -1))
			sup->flags |= LEFT;
		return (arg);
	}
	return (0);
}

void	put_width(t_vec *buf, t_pf *sup, char pos, char padding)
{
	if (sup->width > 1 && (~sup->flags & LEFT) && pos == 'R')
		while (--sup->width)
			ft_vpush_back(buf, &padding, sizeof(char));
	else if (sup->width > 1 && sup->flags & LEFT && pos == 'L')
		while (--sup->width)
			ft_vpush_back(buf, " ", sizeof(char));
}

void	put_full_width(t_vec *buf, t_pf *sup, char pos, char delim)
{
	if (sup->width >= 1 && (~sup->flags & LEFT) && pos == 'R')
		while (sup->width)
		{
			ft_vpush_back(buf, &delim, sizeof(char));
			sup->width--;
		}
	else if (sup->width >= 1 && sup->flags & LEFT && pos == 'L')
		while (sup->width)
		{
			ft_vpush_back(buf, " ", sizeof(char));
			sup->width--;
		}
}

void	do_hash(t_pf *sup, int *wlen, int *h, char type)
{
	if (type == 'x' || type == 'X' || type == 'p')
	{
		sup->hash_symb = (type != 'X' ? "0x" : "0X");
		*h = 2;
	}
	else if (type == 'o' || type == 'O')
	{
		if (sup->preci > 0)
		{
			sup->preci -= 1;
			*wlen -= 1;
		}
		sup->hash_symb = "0";
		*h = 1;
	}
}

void	put_precision_width(t_pf *sup, t_vec *buf, int pr, int h)
{
	if (sup->preci > 0)
	{
		put_full_width(buf, sup, 'R', ' ');
		while (h--)
			ft_vpush_back(buf, sup->hash_symb++, sizeof(char));
		while (sup->preci--)
			ft_vpush_back(buf, "0", sizeof(char));
	}
	else if (sup->width > 0 && sup->flags & ZERO && (~sup->flags & LEFT) &&\
																		pr < 0)
	{
		while (h--)
			ft_vpush_back(buf, sup->hash_symb++, sizeof(char));
		put_full_width(buf, sup, 'R', '0');
	}
	else
	{
		put_full_width(buf, sup, 'R', ' ');
		while (h--)
			ft_vpush_back(buf, sup->hash_symb++, sizeof(char));
	}
}
