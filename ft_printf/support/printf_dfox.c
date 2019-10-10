/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_dfox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:58:06 by chermist          #+#    #+#             */
/*   Updated: 2019/10/10 22:26:58 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putnbr(long long n, t_mdfrs *m)
{
	char	sign;
	char	*p;

	sign = 0;
	m->c_num = count_num(n);
	p = ft_strchr(m->flag, '0');
	nbr_sign(m, &sign, &n, p);
	if (m->pr != -1 && (p ? (*p = 'z') : 1))
		nbr_preci(m, &n, &sign);
	if (p && m->pr == -1)
		(sign) ? write(1, &sign, 1) : 1;
	(m->pr == 0 && n == 0 && m->width != 0) ? m->width++ : 1;
	do_width(m, 'R');
	if (!p && m->pr == -1)
		(sign) ? write(1, &sign, 1) : 1;
	if (m->pr != -1 || (n == INT64_MIN && !
			(ft_strchr(m->flag, '0')) && (sign = '-')))
		(sign) ? write(1, &sign, 1) : 1;
	(m->pr > 0) ? do_preci(m, 1.1, 'o') : 1;
	(m->pr == 0 && n == 0) ? 0 : ft_putnbr(n);
	(m->pr == 0 && n == 0 && m->width == 0) ? m->c_num-- : 1;
	do_width(m, 'L');
}

void	u_pf_putnbr(unsigned long long n, t_mdfrs *m)
{
	char	*p;

	m->c_num = u_count_num(n);
	p = ft_strchr(m->flag, '0');
	if (m->pr != -1 && (p ? (*p = 'z') : 1))
	{
		if ((m->pr == -2 || m->pr == 0))
			m->pr = 0;
		else if (m->pr > m->c_num)
			(m->pr -= m->c_num);
		else
			m->pr = 0;
		m->c_num += m->pr;
	}
	(m->pr == 0 && n == 0 && m->width != 0) ? m->width++ : 1;
	do_width(m, 'R');
	(m->pr > 0) ? do_preci(m, 1.1, 'o') : 1;
	(m->pr == 0 && n == 0) ? 0 : u_ft_putnbr(n);
	(m->pr == 0 && n == 0 && m->width == 0) ? m->c_num-- : 1;
	do_width(m, 'L');
}

void	pf_putdbl(long double d, t_mdfrs *m)
{
	long double	dpart;
	long		ip;
	char		sign;

	sign = 0;
	ip = (long)(d < 0) ? -d : d;
	m->c_num = count_num(ip) + ((d < 0) ? 1 : 0);
	dpart = ((d < 0) ? -d : d) - ip;
	if (ft_strchr(m->flag, '+') && (d > 0) && (sign = '+'))
		(m->c_num)++;
	else if (ft_strchr(m->flag, ' ') && (d > 0) && (sign = ' '))
		(m->c_num)++;
	if (m->pr && (m->pr != -2) && ((m->pr) == -1 ? (m->pr = 6) : 1))
		m->c_num += m->pr + 1;
	else if ((m->pr == -2 || m->pr == 0) && ft_strchr(m->flag, '#'))
		m->c_num++;
	(ft_strchr(m->flag, '0') && d < 0) ? ft_putchar('-') : 1;
	(ft_strchr(m->flag, '0') && sign) ? ft_putchar(sign) : 1;
	do_width(m, 'R');
	(!ft_strchr(m->flag, '0') && sign) ? ft_putchar(sign) : 1;
	(!ft_strchr(m->flag, '0') && d < 0) ? ft_putnbr(-ip) : ft_putnbr(ip);
	if (m->pr && (m->pr != -2) && write(1, ".", 1))
		do_preci(m, dpart, 'f');
	((m->pr == -2 || !m->pr) && ft_strchr(m->flag, '#')) ? ft_putchar('.') : 1;
	do_width(m, 'L');
}

void	sup_base(uintmax_t *num, t_mdfrs *m, int *base, char **int_list)
{
	char *ptr;

	if ((m->spec == 'o' || m->spec == 'O') && (m->pr > 0 ||
	(m->pr != -2 && m->pr != 0 && *num == 0)) &&
	(ptr = ft_strchr(m->flag, '#')))
		*ptr = 'z';
	else if ((m->spec == 'x' || m->spec == 'X')
	&& *num == 0 && (ptr = ft_strchr(m->flag, '#')))
		*ptr = 'z';
	if (m->spec == 'o' || m->spec == 'O')
		*base = 8;
	else if (m->spec == 'x' || m->spec == 'X' || m->spec == 'p')
		*base = 16;
	else if (m->spec == 'b')
		*base = 2;
	(m->spec == 'X') ? (*int_list = "0123456789ABCDEF") :
		(*int_list = "0123456789abcdef");
}

void	pf_base(uintmax_t num, t_mdfrs *m)
{
	char					*int_list;
	char					buff[50];
	char					*ptr;
	int						base;

	sup_base(&num, m, &base, &int_list);
	ptr = &buff[49];
	*ptr = '\0';
	if (!num && ++m->c_num)
		ptr = "0";
	while (num != 0 && ++m->c_num && (*--ptr = int_list[num % base]))
		num /= base;
	if ((m->pr == -2 || m->pr == 0) && *ptr == '0' && (ptr = ""))
		m->c_num = 0;
	((m->c_num < m->pr) && (m->pr = m->pr - m->c_num)) ?
		(m->c_num += m->pr) : (m->pr -= m->c_num);
	(m->spec == 'p' || (ft_strchr(m->flag, '#'))) ? do_hash(m, 0) : 1;
	((m->spec == 'p' || ft_strchr(m->flag, '#')) &&
	ft_strchr(m->flag, '0')) ? do_hash(m, 1) : 1;
	do_width(m, 'R');
	((m->spec == 'p' || ft_strchr(m->flag, '#')) &&
	!ft_strchr(m->flag, '0')) ? do_hash(m, 1) : 1;
	(m->spec != 'p' && m->pr > 0) ? do_preci(m, 1.1, 'o') : 1;
	ft_putstr(ptr);
	do_width(m, 'L');
}
