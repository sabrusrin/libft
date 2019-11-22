/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:06:47 by chermist          #+#    #+#             */
/*   Updated: 2019/11/22 19:53:03 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	exe_(type) function considers type size and calls the function that
**	puts an argument to the ft_printf buffer.
**	Type size encodings:
**	hh-1; h-2; l-4; ll-8; L-16; z-32; j-64; t-128
*/

void	exe_int(va_list ap, char type, t_pf *sup, t_vec *buf)
{
	t_vec	*nbuf;

	nbuf = ft_vnew(20, sizeof(char));
 	if (type != 'D' && sup->length == 0)
		putnbr_buf(sup, buf, strnbr(va_arg(ap, int), nbuf));
	else if (type != 'D' && sup->length == 1)
		putnbr_buf(sup, buf, strnbr_hh(va_arg(ap, int), nbuf));
	else if (type != 'D' && sup->length == 2)
		putnbr_buf(sup, buf, strnbr_h(va_arg(ap, int), nbuf));
	else if ((type != 'D' && sup->length == 4) ||\
											(type == 'O' && sup->length == 0))
		putnbr_buf(sup, buf, strnbr(va_arg(ap, int), nbuf));
	else if (type != 'D' && sup->length == 8)
		putnbr_buf(sup, buf, strnbr_ll(va_arg(ap, long long), nbuf));
	else if (type != 'D' && sup->length == 32)
		putnbr_buf(sup, buf, strnbr_ll((intmax_t)va_arg(ap, ssize_t), nbuf));
 	else if (type != 'D' && sup->length == 64)
		putnbr_buf(sup, buf, strnbr_ll(va_arg(ap, intmax_t), nbuf));
/*	else if (type != 'D' && sup->length == 128)
		putnbr_buf(va_arg(ap, ptrdiff_t), sup, buf); */
	ft_vdel(&nbuf);
}

/* void	exe_octal_hex(va_list ap, char type, t_pf *sup, t_vec *buf)
{
	if (type == 'p' && sup->length == 0)
		putbase_buf(va_arg(ap, long int), type, sup, buf);
	else if (type == 'O' && sup->length == 0)
		putbase_buf(va_arg(ap, unsigned long), type, sup, buf);
	else if (type != 'O' && sup->length == 0)
		putbase_buf(va_arg(ap, unsigned int), type, sup, buf);
	else if (type != 'O' && sup->length == 1)
		putbase_buf(va_arg(ap, unsigned char), type, sup, buf);
	else if (type != 'O' && sup->length == 2)
		putbase_buf(va_arg(ap, unsigned short), type, sup, buf);
	else if (type != 'O' && sup->length == 4)
		putbase_buf(va_arg(ap, unsigned long), type, sup, buf);
	else if (type != 'O' && sup->length == 8)
		putbase_buf(va_arg(ap, unsigned long long), type, sup, buf);
	else if (type != 'O' && sup->length == 32)
		putbase_buf(va_arg(ap, size_t), type, sup, buf);
	else if (type != 'O' && sup->length == 64)
		putbase_buf(va_arg(ap, uintmax_t), type, sup, buf);
} */

/* void	exe_unsigned(va_list ap, char type, t_pf *sup, t_vec *buf)
{
	if (type == 'u' && sup->length == 0)
		putunbr_buf(va_arg(ap, unsigned int), sup, buf);
	else if (type == 'u' && sup->length == 1)
		putunbr_buf(va_arg(ap, unsigned char), sup, buf);
	else if (type == 'u' && sup->length == 2)
		putunbr_buf(va_arg(ap, unsigned short), sup, buf);
	else if ((type == 'u' && sup->length == 4) ||\
											(type == 'U' && sup->length == 0))
		putunbr_buf(va_arg(ap, unsigned long), sup, buf);
	else if (type == 'u' && sup->length == 8)
		putunbr_buf(va_arg(ap, unsigned long long), sup, buf);
	else if (type == 'u' && sup->length == 32)
		putunbr_buf(va_arg(ap, size_t), sup, buf);
	else if (type == 'u' && sup->length == 64)
		putunbr_buf(va_arg(ap, uintmax_t), sup, buf);
} */

void	exe_char_string(va_list ap, char type, t_pf *sup, t_vec *buf)
{
	if (type == 'c' && sup->length == 0)
		putchar_buf(va_arg(ap, int), type, sup, buf);
	else if ((type == 'c' && sup->length == 4) ||\
											(type == 'C' && sup->length == 0))
		putchar_buf(va_arg(ap, wint_t), type, sup, buf);
	else if (type == 's' && sup->length == 0)
		putstr_buf(va_arg(ap, char*), type, sup, buf);
	else if ((type == 's' && sup->length == 4) ||\
											(type == 'S' && sup->length == 0))
		putlstr_buf(va_arg(ap, wchar_t*), type, sup, buf);
}

/* void	exe_double(va_list ap, char type, t_pf *sup, t_vec *buf)
{
	if (type == 'f' && sup->length == 0)
		putfloat_buf(va_arg(ap, float), type, sup, buf);
	else if (type == 'f' && sup->length == 4)
		putdouble_buf(va_arg(ap, double), type, sup, buf);
	else if (type == 'f' && sup->length == 16)
		putdouble_buf(va_arg(ap, long double), type, sup, buf);
} */
