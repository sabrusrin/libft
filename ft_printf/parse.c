/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:05:31 by chermist          #+#    #+#             */
/*   Updated: 2019/12/03 21:36:04 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	parses the type field
*/

void	parse_type(va_list ap, char **str, t_pf *sup, t_vec *buf)
{
	if (str && *str && IS_TYPE(**str))
	{
		if (**str == 'd' || **str == 'i' || **str == 'D')
			exe_int(ap, **str, sup, buf);
		else if (**str == 'o' || **str == 'O')
			exe_octal_hex(ap, **str, sup, buf);
		else if (**str == 'u' || **str == 'U')
			exe_unsigned(ap, **str, sup, buf);
		else if (**str == 'x' || **str == 'X' || **str == 'p')
			exe_octal_hex(ap, **str, sup, buf);
/* 		else if (**str == 'f' || **str == 'F')
			exe_double(ap, **str, sup, buf);
		else if (**str == 'a' || **str == 'A')
			write(1, "\nnot implemented yet ¯\\_(ツ)_/¯\n", 31); */
		else if (**str == 'c' || **str == 'C')
			exe_char_string(ap, **str, sup, buf);
		else if (**str == 's' || **str == 'S')
			exe_char_string(ap, **str, sup, buf);
		++(*str);
	}
}

/*
**	parses the length field, that specifies the size of the argument
**	Type size encodings:
**	hh-1; h-2; l-4; ll-8; L-16; z-32; j-64; t-128
*/

void	parse_length_field(char **str, t_pf *sup)
{
	if (str && *str && IS_LENGTH(**str))
	{
		if (**str == 'h' && *(*str + 1) == 'h' && (*str += 2))
			sup->length = 1;
		else if (**str == 'l' && *(*str + 1) == 'l' && (*str += 2))
			sup->length = 8;
		else if (**str == 'h' && ++(*str))
			sup->length = 2;
		else if (**str == 'l' && ++(*str))
			sup->length = 4;
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
**	parses width and precision fields
*/

void	parse_width_preci(va_list ap, char **str, t_pf *sup)
{
	if (str && *str)
	{
		if (**str && (ft_isdigit(**str) || **str == '*'))
		{
			if (**str == '*')
				sup->wild = ft_wildcard(ap, str, sup);
			if (ft_isdigit(**str))
				sup->width = ft_atoi_move(str);
			else
				sup->width = sup->wild;
		}
		if (**str == '.' && (ft_isdigit(*(*str + 1)) || *(*str + 1) == '*'))
		{
			if (*(++(*str)) != '*')
				sup->preci = ft_atoi_move(str);
			else
			{
				sup->wild = ft_wildcard(ap, str, sup);
				sup->preci = sup->wild;
			}
		}
		else if (**str == '.' && ++*str)
			sup->preci = -2;
	}
}

/*
**	parses flag field; flags	#0- +
*/

void	parse_flags(char **str, t_pf *sup, t_vec *buf)
{
	set_default(sup);
	if (str && *str)
		while (**str && IS_FLAG(**str))
		{
			if (**str == '%')
				ft_vpush_back(buf, "%", sizeof(char));
			else if (**str == '#')
				sup->flags |= HASH;
			else if (**str == '0')
				sup->flags |= ZERO;
			else if (**str == '-')
				sup->flags |= LEFT;
			else if (**str == ' ' && (~sup->flags & PLUS))
				sup->flags |= SPACE;
			else if (**str == '+')
			{
				sup->flags |= PLUS;
				if (sup->flags & SPACE)
					sup->flags ^= SPACE;
			}
			++(*str);
		}
}

/*
**	%[flags][width][.precision][length]type
*/

int		parse_format(va_list ap, const char *format, t_vec *buf, t_pf *sup)
{
	char	*str;

	str = (char*)format;
	while (*str)
	{
		if (sup->kill)
			return (FALSE);
		if (*str != '%')
			ft_vpush_back(buf, str, sizeof(char));
		else if (*(str + 1))
		{
			++str;
			if (*str == '%')
				ft_vpush_back(buf, str++, sizeof(char));
			else if (*str)
			{
				parse_flags(&str, sup, buf);
				parse_width_preci(ap, &str, sup);
				parse_length_field(&str, sup);
				parse_type(ap, &str, sup, buf);
			}
			continue ;
		}
		++str;
	}
	return (TRUE);
}
