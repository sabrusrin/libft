/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:08:38 by chermist          #+#    #+#             */
/*   Updated: 2019/12/03 22:26:02 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* int		ft_vsnprintf(char *str, size_t size, const char *format, ...)
{
	va_list	ap;
	t_vec	*buf;
	t_pf	sup;
	int		sz;

	sz = 0;
	if ((buf = ft_vnew(size, sizeof(char))))
	{
		va_start(ap, format);
		set_default(&sup);
		if (parse_format(ap, format, buf, &sup))
			sz = buf->size;
		else
			sz = -1;
		write(fd, buf->data, buf->size);
		ft_vdel(&buf);
		va_end(ap);
	}
	return (sz);
} */

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	t_vec	*buf;
	t_pf	sup;
	int		sz;

	sz = 0;
	if ((buf = ft_vnew(1000, sizeof(char))))
	{
		va_start(ap, format);
		set_default(&sup);
		if (parse_format(ap, format, buf, &sup))
			sz = buf->size;
		else
			sz = -1;
		write(fd, buf->data, buf->size);
		ft_vdel(&buf);
		va_end(ap);
	}
	return (sz);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_vec	*buf;
	t_pf	sup;
	int		sz;

	sz = 0;
	if ((buf = ft_vnew(1000, sizeof(char))))
	{
		va_start(ap, format);
		set_default(&sup);
		if (parse_format(ap, format, buf, &sup))
			sz = buf->size;
		else
			sz = -1;
		write(1, buf->data, buf->size);
		ft_vdel(&buf);
		va_end(ap);
	}
	return (sz);
}
