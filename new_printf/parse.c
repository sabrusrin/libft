/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:05:31 by chermist          #+#    #+#             */
/*   Updated: 2019/11/18 17:47:17 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

/*
**	%[parameter][flags][width][.precision][length]type
*/
char	*parse_type(va_list ap, char *str, t_pf *sup)
{

}

/*
**	parses the length field, that specifies the size of the argument
*/
char	*parse_length_field(char *str, t_pf *sup)
{

}

/*
**	will parse flags #0- + ; width and precision
*/
char	*parse_flags(char *str, t_pf *sup)
{
	set_default(sup);
	while (*str && ft_strchr(FLAGS, *str))
	{

		++str;
	}
	if (*str && ft_isdigit(*str))
		sup->width = ft_atoi_move(&str);
	if (*str == '.' && ft_isdigit(*(str + 1)))
		sup->preci = ft_atoi_move(&(++str));
	return (str);
}

char	*parse_specifier(va_list ap, char *str, t_vec *buf, t_pf *sup)
{
	if (str)
	{
		if (*str == '%')
			ft_vpush_back(buf, str, sizeof(char));
		else
		{
			str = parse_flags(str, sup);
			str = parse_length_field(str, sup);
			str = parse_type(ap, str, sup);
		}
	}
	return (str);
}

void	parse_format(va_list ap, const char *format, t_vec *buf, t_pf *sup)
{
	char	*str;

	str = (char*)format;
	while (*str)
	{
		if (*str != '%')
			ft_vpush_back(buf, str, sizeof(char));
/* 		else
			if (!*(str = parse_specifier(ap, ++str, buf, sup)) || !str)
				return ; */
		++str;
	}
}
