/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 22:19:55 by chermist          #+#    #+#             */
/*   Updated: 2019/10/10 22:25:57 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_width(t_mdfrs *m, char f)
{
	char	fl;
	int		c;
	int		ch;

	c = 0;
	fl = ' ';
	ch = ft_strchr(m->flag, '-') ? 1 : 0;
	if (ft_strchr(m->flag, '0') && !ch)
		fl = '0';
	if ((f == 'R') && !ch && (m->width))
		while ((m->width)-- > m->c_num && ++c)
			write(1, &fl, 1);
	if ((f == 'L') && ch && (m->width))
		while ((m->width)-- > m->c_num && ++c)
			write(1, &fl, 1);
	m->c_num += c;
}

void	do_hash(t_mdfrs *m, int f)
{
	if (!f && (m->spec == 'o' || m->spec == 'O'))
		m->c_num++;
	else if (!f && (m->spec == 'x' || m->spec == 'X' || m->spec == 'p'))
		m->c_num += 2;
	if ((f == 1) && (m->spec == 'x' || m->spec == 'X' ||
				((m->spec == 'p') ? (m->spec = 'x') : 0)))
	{
		ft_putchar('0');
		ft_putchar(m->spec);
	}
	else if ((f == 1) && (m->spec == 'o' || m->spec == 'O'))
		ft_putchar('0');
}

void	do_preci(t_mdfrs *m, long double dpart, char c)
{
	int	i;

	i = 0;
	if (c == 'f')
	{
		dpart = dpart * ft_pow(10, m->pr + 1);
		dpart = (((long)dpart % 10) > 4) ? dpart / 10 + 1 : dpart / 10;
		ft_putnbr((long)dpart);
	}
	else if (c == 'o')
	{
		i = m->pr;
		while (i--)
			ft_putchar('0');
	}
}

void	nbr_preci(t_mdfrs *m, long long *n, char *sign)
{
	if ((m->pr == -2 || m->pr == 0))
		m->pr = 0;
	else if ((*sign == '-' || ((*n < 0 && (*sign = '-') ?
			(*n = -*n) : 0))) && (m->pr > m->c_num - 1))
		m->pr -= m->c_num - 1;
	else if ((*n >= 0 && *sign != '-' && *sign != '+' && m->pr > m->c_num)
			|| ((*sign == '+' || *sign == ' ') && m->pr > m->c_num - 1))
		(*sign == '+' || *sign == ' ') ? (m->pr -= m->c_num - 1) :
			(m->pr -= m->c_num);
	else
		m->pr = 0;
	m->c_num += m->pr;
}

void	nbr_sign(t_mdfrs *m, char *sign, long long *n, char *p)
{
	if (m->spec != 'u' && m->spec != 'U' &&
	ft_strchr(m->flag, '+') && *n >= 0 && (*sign = '+'))
		(m->c_num)++;
	else if (m->spec != 'u' && m->spec != 'U' &&
	ft_strchr(m->flag, '+') && *n < 0 && (*sign = '-'))
		*n = -*n;
	else if (m->spec != 'u' && m->spec != 'U' &&
	p && (*n < 0) && (*sign = '-'))
		*n = -*n;
	else if (m->spec != 'u' && m->spec != 'U' &&
	ft_strchr(m->flag, ' ') && *n >= 0 && (*sign = ' '))
		(m->c_num)++;
}
