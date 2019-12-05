/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:46:01 by chermist          #+#    #+#             */
/*   Updated: 2019/12/05 00:20:10 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_default(t_pf *sup)
{
	sup->flags = 0;
	sup->length = 0;
	sup->width = 0;
	sup->ul = 0;
	sup->pad_char = ' ';
	sup->sign = '+';
	sup->preci = -1;
	sup->wild = 1;
	sup->hash_symb = NULL;
	sup->kill = FALSE;
}

int		precision_len(wchar_t *s, t_pf *sup)
{
	t_vec	*buf;
	int		tmp;
	int		printable;
	int		bytes;
	int		i;

	i = 0;
	buf = ft_vnew(1000, sizeof(char));
	tmp = sup->preci;
	printable = 0;
	while (tmp > 0)
	{
		if (tmp > 4)
			tmp -= buf_wchar(*s, buf, 0);
		else
		{
			bytes = wchar_bytes(*s);
			tmp -= buf_wchar(*s, buf,\
			(tmp > bytes ? bytes : tmp));
		}
		s++;
	}
	printable = buf->size;
	ft_vdel(&buf);
	return (printable);
}

int		wchar_bytes(wint_t c)
{
	if (c <= 127)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else if (c < 2097152)
		return (4);
	return (-1);
}

void	str_to_buf(char *s, t_vec *buf)
{
	while (*s)
		ft_vpush_back(buf, s++, sizeof(char));
}

size_t	ft_lstrlen(const wchar_t *s)
{
	size_t count;

	count = 0;
	while (*s)
	{
		if (*s <= 127)
			count += 1;
		else if (*s < 2048)
			count += 2;
		else if (*s < 65536)
			count += 3;
		else if (*s < 2097152)
			count += 4;
		s++;
	}
	return (count);
}
