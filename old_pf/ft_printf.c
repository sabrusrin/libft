/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:27:33 by chermist          #+#    #+#             */
/*   Updated: 2019/11/17 19:32:51 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	int		result;
	va_list ap;

	result = 0;
	va_start(ap, format);
	result = parse(format, ap);
	va_end(ap);
	return (result);
}
