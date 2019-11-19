/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:08:38 by chermist          #+#    #+#             */
/*   Updated: 2019/11/20 01:48:58 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
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
	sup->preci = -1;
	sup->kill = FALSE;
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

int		main(void)
{
	int	d;
	const wchar_t emoji = 0x1F607;
	wchar_t	wstr[8] = {128519, 40, 128519, 40, 128519, 40, 128519, 0};
	char	*loc;
	char	*str;

	str = "Hi how is it going! I'm writing this message to test printf";
	loc = setlocale(LC_ALL, "");
	printf("\n%s\n\n", loc);
	d = f_printf("Привет, меня зовут Рустам.	|%-5c|%-10lc | %20.19s|%-15S|",\
												'h', L'😇', str, L"Привет");
	printf("\n%d\n", d);
	d = printf("Привет, меня зовут Рустам.	|%-5c|%-10lc | %20.19s|%-15S| %.9d",\
												'h', L'😇', str, L"Привет", 2222);
	printf("\n%d", d);
	return (0);
}