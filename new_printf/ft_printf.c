/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:08:38 by chermist          #+#    #+#             */
/*   Updated: 2019/11/18 02:26:48 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"
#include "libft.h"
#include <stdio.h>

#define LENGTH "lLhjz"
#define TYPE "dDioOuUxXfFeEcCsSpaAgGpb"
#define FLAGS "#0- +'"

void	parse_type(va_list ap, char *str, t_pf *sup)
{

}

void	parse_length_field(char *str, t_pf *sup)
{

}

void	parse_flags(char *str, t_pf *sup)
{
	while (*str && ft_strchr(FLAGS, *str))
	{

	}
}

char	*parse_specifier(va_list ap, char *str, t_vec *buf, t_pf *sup)
{
	if (*str == '%')
		ft_vpush_back(buf, str, sizeof(char));
	else
	{
		parse_flags(str, sup);
		parse_length_field(str, sup);
		parse_type(ap, str, sup);
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
			if (!*(str = parse_specifier(ap, ++str, buf, sup)))
				return ; */
		++str;
	}
}

int		f_printf(const char *format, ...)
{
	va_list	ap;
	t_vec	*buf;
	t_pf	sup;
	int		sz;

	sz = 0;
	if ((buf = ft_vnew(100, sizeof(char))))
	{
		va_start(ap, format);
		parse_format(ap, format, buf, &sup);
		write(1, buf->data, buf->size);
		sz = buf->size;
		ft_vdel(&buf);
		va_end(ap);
	}
	return (sz);
}

int	main(void)
{
	int	d;

	d = f_printf("Привет, меня зовут Рустам");
	printf("\n%d\n", d);
	d = printf("Привет, меня зовут Рустам");
	printf("\n%d", d);
	return (0);
}
