/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:42:39 by chermist          #+#    #+#             */
/*   Updated: 2019/10/10 22:26:11 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		save_mdfr(char **str, t_mdfrs *m)
{
	int				current;

	current = 0;
	if (**str == 'L' && (current = 7) && (*str += 1))
		m->modifier = (current > m->modifier) ? current : m->modifier;
	else if (**str == 'z' && (current = 6) && (*str += 1))
		m->modifier = (current > m->modifier) ? current : m->modifier;
	else if (**str == 'j' && (current = 5) && (*str += 1))
		m->modifier = (current > m->modifier) ? current : m->modifier;
	else if (**str == 'l' && (*(*str + 1) == 'l') &&
	(*str += 2) && (current = 4))
		m->modifier = (current > m->modifier) ? current : m->modifier;
	else if (**str == 'l' && (current = 3) && (*str += 1))
		m->modifier = (current > m->modifier) ? current : m->modifier;
	else if (**str == 'h' && (*(*str + 1) == 'h') &&
	(*str += 2) && (current = 1))
		m->modifier = (current > m->modifier) ? current : m->modifier;
	else if (**str == 'h' && (current = 2) && (*str += 1))
		m->modifier = (current > m->modifier) ? current : m->modifier;
}

void		ft_wildcard(t_mdfrs *mods, char **str, va_list ap)
{
	int	k;

	k = 0;
	if (**str == '*' && (*str)++)
	{
		k = va_arg(ap, int);
		if (k < 0 && *(*str - 2) != '.' && (k *= -1))
			mods->flag[6] = '-';
		if (*(*str - 2) == '.')
			(k >= 0) ? (mods->pr = k) :
		(mods->pr = -1);
		else
			(ft_isdigit(**str)) ? (mods->width = 0) :
			(mods->width = k);
	}
}

char		*parse_modifier(char *str, t_mdfrs *mods, va_list ap)
{
	int j;

	j = 0;
	while (ALLMDFR(*str))
	{
		while (FLAGS(*str) && !(mods->flag[j + 1] = 0))
		{
			if (j >= 5 && str++)
				break ;
			if (!(ft_strchr(mods->flag, *str++)))
				mods->flag[j++] = *(str - 1);
			if (!(*str))
				return (str);
		}
		ft_wildcard(mods, &str, ap);
		while (ft_isdigit(*str) && (*(str - 1)))
			mods->width = (mods->width * 10) + (*str++ - '0');
		if (*str == '.' && ((mods->pr = -2) && ft_isdigit(*(str + 1)) ?
			!(mods->pr = 0) : !(*str++)))
			while (ft_isdigit(*++str))
				mods->pr = (mods->pr * 10) + (*str - '0');
		(MDFR(*str)) ? save_mdfr(&str, mods) : 0;
	}
	mods->spec = *str;
	return (str);
}

size_t		parse(const char *format, va_list ap)
{
	char	*str;
	size_t	i;
	t_mdfrs mods;
	int		*count;

	str = (char*)format;
	i = 0;
	mods.c_num = 0;
	while (*str != '\0')
	{
		clean_mods(&mods);
		while (*str != '%' && ++i)
		{
			ft_putchar(*str++);
			if (!(*str))
				return (i);
		}
		if (!(*(str = parse_modifier(++str, &mods, ap))))
			return (i);
		if (*str == 'n' && (count = va_arg(ap, int*)))
			*count = i;
		i += spec_exe(str, ap, &mods);
		str++;
	}
	return (i);
}
