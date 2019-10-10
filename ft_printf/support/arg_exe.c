/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:48:47 by chermist          #+#    #+#             */
/*   Updated: 2019/10/10 22:25:06 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		spec_exe(char *spec, va_list ap, t_mdfrs *mods)
{
	if (*spec == 'c' || *spec == 'C')
		pf_putchar(va_arg(ap, int), mods);
	if (*spec == 'd' || *spec == 'D' || *spec == 'i')
		d_type_parse(ap, mods);
	if (*spec == 'u' || *spec == 'U')
		u_type_parse(ap, mods);
	if (*spec == 'f' || *spec == 'F')
		(mods->modifier == 7) ? (pf_putdbl(va_arg(ap, long double), mods)) :
			(pf_putdbl(va_arg(ap, double), mods));
	if (*spec == 's' && mods->modifier != 3)
		pf_putstr(va_arg(ap, char*), mods);
	if (*spec == 'S' || (*spec == 's' && mods->modifier == 3))
		l_pf_putstr(va_arg(ap, int*), mods);
	if (*spec == 'x' || *spec == 'X' || *spec == 'o'
	|| *spec == 'O' || *spec == 'b')
		x_type_parse(ap, mods);
	if (!SPCFR(*spec))
		pf_putchar(*spec, mods);
	if (*spec == 'p')
		(pf_base(va_arg(ap, long int), mods));
	return (mods->c_num);
}

void		d_type_parse(va_list ap, t_mdfrs *m)
{
	if (m->spec == 'D')
	{
		pf_putnbr(va_arg(ap, long), m);
		return ;
	}
	if ((m->modifier == 4) || m->modifier == 6 || m->modifier == 5)
		pf_putnbr(va_arg(ap, long long), m);
	else if (m->modifier == 3)
		pf_putnbr(va_arg(ap, long), m);
	else if (m->modifier == 1)
		pf_putnbr((char)va_arg(ap, int), m);
	else if (m->modifier == 2)
		pf_putnbr((short)va_arg(ap, int), m);
	else
		pf_putnbr(va_arg(ap, int), m);
}

void		x_type_parse(va_list ap, t_mdfrs *m)
{
	if (m->spec == 'O')
	{
		pf_base(va_arg(ap, long), m);
		return ;
	}
	if ((m->modifier == 4) || m->modifier == 5 || m->modifier == 6)
		pf_base(va_arg(ap, unsigned long long), m);
	else if (m->modifier == 3)
		pf_base(va_arg(ap, unsigned long), m);
	else if (m->modifier == 1)
		pf_base((unsigned char)va_arg(ap, unsigned int), m);
	else if (m->modifier == 2)
		pf_base((unsigned short)va_arg(ap, unsigned int), m);
	else
		pf_base(va_arg(ap, unsigned int), m);
}

void		u_type_parse(va_list ap, t_mdfrs *m)
{
	if (m->spec == 'U')
	{
		u_pf_putnbr(va_arg(ap, unsigned long), m);
		return ;
	}
	if ((m->modifier == 4) || m->modifier == 5 || m->modifier == 6)
		u_pf_putnbr(va_arg(ap, unsigned long long), m);
	else if (m->modifier == 3)
		u_pf_putnbr(va_arg(ap, unsigned long), m);
	else if (m->modifier == 1)
		u_pf_putnbr((unsigned char)va_arg(ap, unsigned int), m);
	else if (m->modifier == 2)
		u_pf_putnbr((unsigned short)va_arg(ap, unsigned int), m);
	else
		u_pf_putnbr(va_arg(ap, unsigned int), m);
}
