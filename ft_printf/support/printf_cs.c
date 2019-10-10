/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_cs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:10:04 by chermist          #+#    #+#             */
/*   Updated: 2019/10/11 00:07:53 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putchar(int c, t_mdfrs *m)
{
	int a;

	m->c_num++;
	do_width(m, 'R');
	if (m->spec == 'c' && m->modifier != 3)
	{
		ft_putchar(c);
		a = 1;
	}
	else
		a = l_ft_putchar(c);
	do_width(m, 'L');
	m->c_num += a - 1;
}

void	pf_putstr(char *s, t_mdfrs *m)
{
	char	*tmp;
	int		save;

	((s == 0 && (m->pr == -1 || m->pr > 0)) ? (s = "(null)") : 0);
	tmp = s;
	if (s != 0)
	{
		while (*tmp++)
			m->c_num++;
		if (((!m->pr || m->pr == -2) && (m->pr = -2)) ?
		!(s = 0) : 0)
			m->c_num = 0;
		else if ((m->pr > 0 && (m->pr < m->c_num)) && (tmp = malloc(m->pr + 1)))
		{
			tmp[m->pr] = 0;
			ft_memcpy(tmp, s, m->pr);
			s = tmp;
			m->c_num = m->pr;
		}
	}
	save = m->c_num;
	do_width(m, 'R');
	(s != 0) ? ft_putstr(s) : 0;
	do_width(m, 'L');
	(m->pr > 0 && s != 0 && (m->pr < save)) ? free(tmp) : 1;
}

void	l_pf_putstr(int *s, t_mdfrs *m)
{
	int		*tmp;
	int		save;
	int		count;

	count = 0;
	((s == 0 && (m->pr == -1 || m->pr > 0)) ? (s = L"(null)") : 0);
	tmp = s;
	if (s != 0)
	{
		while (m->pr > 0 && *tmp && m->c_num < m->pr && ++count)
		{
			save = m->c_num;
			m->c_num += count_utf_bytes(*tmp++);
			if (m->c_num > m->pr && (m->c_num = save) && count--)
				break ;
		}
		while (m->pr == -1 && *tmp && ++count)
			m->c_num += count_utf_bytes(*tmp++);
		if (((!m->pr || m->pr == -2) && (m->pr = -2)) ?
		!(s = 0) : 0)
			m->c_num = 0;
	}
	do_width(m, 'R');
	(s != 0) ? l_ft_putstr(s, count) : 0;
	do_width(m, 'L');
}
