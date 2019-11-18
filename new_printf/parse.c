/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:05:31 by chermist          #+#    #+#             */
/*   Updated: 2019/11/18 21:27:00 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"

void	parse_type(va_list ap, char **str, t_pf *sup)
{

}

/*
**	parses the length field, that specifies the size of the argument
*/
void	parse_length_field(char **str, t_pf *sup)
{
	if (str && *str)
	{
		if (**str == 'h' && *(*str + 1) == 'h' && (*str += 2))
			sup->length = 1;
		else if (**str == 'h' && ++(*str))
			sup->length = 2;
		else if (**str == 'l' && ++(*str))
			sup->length = 4;
		else if (**str == 'l' && *(*str + 1) == 'l' && (*str += 2))
			sup->length = 8;
		else if (**str == 'L' && ++(*str))
			sup->length = 16;
		else if (**str == 'z' && ++(*str))
			sup->length = 32;
		else if (**str == 'j' && ++(*str))
			sup->length = 64;
		else if (**str == 't' && ++(*str))
			sup->length = 128;
	}
}
/*
**	parses width and precision
*/
void	parse_width_preci(va_list ap, char **str, t_pf *sup)
{
	if (str && *str)
	{
		if (**str && (ft_isdigit(**str) || **str == '*'))
		{
			if (**str != '*')
				sup->width = ft_atoi_move(str);
			else
				sup->width = ft_wildcard(ap, str, sup);
		}
		if (**str == '.' && (ft_isdigit(*(*str + 1)) || *(*str + 1) == '*'))
		{
			if (*(++(*str)) != '*')
				sup->preci = ft_atoi_move(str);
			else
				sup->preci = ft_wildcard(ap, str, sup);
		}
	}
}
/*
**	will parse flags #0- +
*/
void	parse_flags(char **str, t_pf *sup)
{
	set_default(sup);
	if (str && *str)
		while (**str && ft_strchr(FLAG, **str))
		{
			if (**str == '#')
				sup->hash = '#';
			else if (**str == '0')
				sup->zero = '0';
			else if (**str == '-')
				sup->minus = '-';
			else if (**str == ' ' && sup->plus != '+')
				sup->space = ' ';
			else if (**str == '+')
			{
				sup->plus = '+';
				if (sup->space == ' ')
					sup->space = 0;
			}
			++(*str);
		}
}
/*
**	%[parameter][flags][width][.precision][length]type
*/
void	parse_format(va_list ap, const char *format, t_vec *buf, t_pf *sup)
{
	char	*str;

	str = (char*)format;
	while (*str)
	{
		if (*str != '%')
			ft_vpush_back(buf, str, sizeof(char));
 		else if (*(++str))
		{
			if (*str && *str == '%')
				ft_vpush_back(buf, str++, sizeof(char));
			else if (*str)
			{
				parse_flags(&str, sup);
				parse_width_preci(ap, &str, sup);
				parse_length_field(&str, sup);
				parse_type(ap, &str, sup);
			}
			continue ;
		}
		++str;
	}
}
/*
char	*parse_specifier(va_list ap, char *str, t_vec *buf, t_pf *sup)
{
	if (str)
	{
		if (*str == '%')
			ft_vpush_back(buf, str, sizeof(char));
		else
		{
			str = parse_flags(ap, str, sup);
			str = parse_width_preci(ap, &str, sup);
			str = parse_length_field(str, sup);
			str = parse_type(ap, str, sup);
		}
	}
	return (str);
}
 */
