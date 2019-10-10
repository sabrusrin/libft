/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:07:47 by chermist          #+#    #+#             */
/*   Updated: 2019/10/11 00:15:51 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clean_mods(t_mdfrs *m)
{
	int i;

	i = -1;
	while (++i < 7)
		m->flag[i] = '|';
	m->c_num = 0;
	m->modifier = 0;
	m->width = 0;
	m->pr = -1;
	m->spec = 0;
}

int		count_num(long long i)
{
	static int	count = 0;

	count = 0;
	if (i == INT64_MIN)
		return (20);
	if ((i < 0) && (i = -i))
		count++;
	while (i / 10 > 0)
	{
		++count;
		i /= 10;
	}
	return (++count);
}

int		u_count_num(unsigned long long i)
{
	static int	count = 0;

	count = 0;
	while (i / 10 > 0)
	{
		++count;
		i /= 10;
	}
	return (++count);
}
