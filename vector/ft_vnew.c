/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:51:46 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 19:14:52 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_vnew(size_t n, size_t type_sz)
{
	t_vec	*v;

	v = NULL;
	if (n && type_sz && (v = (t_vec*)malloc(sizeof(t_vec))))
	{
		v->type_sz = type_sz;
		v->capacity = n;
		v->size = 0;
		if (!(v->data = malloc(n * type_sz)))
			ft_memdel((void**)&v);
	}
	return (v);
}
