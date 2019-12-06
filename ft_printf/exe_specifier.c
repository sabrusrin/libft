/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:06:47 by chermist          #+#    #+#             */
/*   Updated: 2019/12/06 21:19:59 by chermist         ###   ########.fr       */
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

	nbuf = ft_vnew(30, sizeof(char));
	if ((type != 'D' && sup->length == 4) || type == 'D')
		putnbr_buf(sup, buf, itoa_buf(va_arg(ap, long), nbuf));
	else if (sup->length == 0)
		putnbr_buf(sup, buf, itoa_buf(va_arg(ap, int), nbuf));
	else if (sup->length == 1)
		putnbr_buf(sup, buf, itoa_buf((signed char)va_arg(ap, int), nbuf));
	else if (sup->length == 2)
		putnbr_buf(sup, buf, itoa_buf((short)va_arg(ap, int), nbuf));
	else if (sup->length == 8)
		putnbr_buf(sup, buf, itoa_buf(va_arg(ap, long long), nbuf));
	else if (sup->length == 32)
		putnbr_buf(sup, buf, itoa_buf((intmax_t)va_arg(ap, ssize_t), nbuf));
	else if (sup->length == 64)
		putnbr_buf(sup, buf, itoa_buf(va_arg(ap, intmax_t), nbuf));
	else if (sup->length == 128)
		putnbr_buf(sup, buf, itoa_buf(va_arg(ap, __PTRDIFF_TYPE__), nbuf));
	ft_vdel(&nbuf);
}

void	exe_octal_hex(va_list ap, char type, t_pf *sup, t_vec *buf)
{
	t_vec	*nbuf;

	nbuf = ft_vnew(30, sizeof(char));
	if ((type != 'O' && sup->length == 4) || type == 'O' || type == 'p')
		putbase_buf(sup, buf, type, \
			itoa_base_buf(va_arg(ap, unsigned long), nbuf, sup, type));
	else if (sup->length == 0)
		putbase_buf(sup, buf, type, \
			itoa_base_buf(va_arg(ap, uint32_t), nbuf, sup, type));
	else if (sup->length == 1)
		putbase_buf(sup, buf, type, \
			itoa_base_buf((uint8_t)va_arg(ap, uint32_t), nbuf, sup, type));
	else if (sup->length == 2)
		putbase_buf(sup, buf, type, \
			itoa_base_buf((uint16_t)va_arg(ap, uint32_t), nbuf, sup, type));
	else if (sup->length == 8)
		putbase_buf(sup, buf, type, \
			itoa_base_buf(va_arg(ap, uint64_t), nbuf, sup, type));
	else if (sup->length == 32)
		putbase_buf(sup, buf, type, \
			itoa_base_buf(va_arg(ap, size_t), nbuf, sup, type));
	else if (sup->length == 64)
		putbase_buf(sup, buf, type, \
			itoa_base_buf(va_arg(ap, uintmax_t), nbuf, sup, type));
	ft_vdel(&nbuf);
}

void	exe_unsigned(va_list ap, char type, t_pf *sup, t_vec *buf)
{
	t_vec	*nbuf;

	if (sup->flags & PLUS)
		sup->flags ^= PLUS;
	if (sup->flags & SPACE)
		sup->flags ^= SPACE;
	nbuf = ft_vnew(30, sizeof(char));
	if ((type == 'u' && sup->length == 4) || type == 'U')
		putnbr_buf(sup, buf, uitoa_buf(va_arg(ap, unsigned long), nbuf));
	else if (sup->length == 0)
		putnbr_buf(sup, buf, uitoa_buf(va_arg(ap, uint32_t), nbuf));
	else if (sup->length == 1)
		putnbr_buf(sup, buf, uitoa_buf((uint8_t)va_arg(ap, uint32_t), nbuf));
	else if (sup->length == 2)
		putnbr_buf(sup, buf, uitoa_buf((uint16_t)va_arg(ap, uint32_t), nbuf));
	else if (sup->length == 8)
		putnbr_buf(sup, buf, uitoa_buf(va_arg(ap, uint64_t), nbuf));
	else if (sup->length == 32)
		putnbr_buf(sup, buf, uitoa_buf(va_arg(ap, size_t), nbuf));
	else if (sup->length == 64)
		putnbr_buf(sup, buf, uitoa_buf(va_arg(ap, uintmax_t), nbuf));
	ft_vdel(&nbuf);
}

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
