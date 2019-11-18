/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:08:38 by chermist          #+#    #+#             */
/*   Updated: 2019/11/18 20:59:35 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f_printf.h"
#include "libft.h"
#include <stdio.h>

void	set_default(t_pf *sup)
{
	sup->length = 0;
	sup->hash = 0;
	sup->zero = 0;
	sup->minus = 0;
	sup->space = 0;
	sup->plus = 0;
	sup->width = 0;
	sup->preci = 0;
}

int		f_printf(const char *format, ...)
{
	va_list	ap;
	t_vec	*buf;
	t_pf	sup;
	int		sz;

	sz = 0;
	if ((buf = ft_vnew(100, sizeof(char))))
	{
		va_start(ap, format);
		set_default(&sup);
		parse_format(ap, format, buf, &sup);
		write(1, buf->data, buf->size);
		sz = buf->size;
		ft_vdel(&buf);
		va_end(ap);
	}
	return (sz);
}

int	main(void)
{
	int	d;

	d = f_printf("Привет, меня зовут Рустам");
	printf("\n%d\n", d);
	d = printf("Привет, меня зовут Рустам");
	printf("\n%d", d);
	return (0);
}
