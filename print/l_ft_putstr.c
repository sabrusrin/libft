/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_ft_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:31:45 by chermist          #+#    #+#             */
/*   Updated: 2019/10/11 00:13:04 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	l_ft_putstr(int *s, int i)
{
	int count;

	count = 0;
	if (!s)
		return (0);
	while (*s && i--)
	{
		count += l_ft_putchar(*s);
		s++;
	}
	return (count);
}
