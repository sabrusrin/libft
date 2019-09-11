/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpush_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:51:28 by chermist          #+#    #+#             */
/*   Updated: 2019/09/11 15:28:17 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	ft_vpush_back(t_vec *v, void *val, size_t val_sz)
{
	unsigned char	*tmp;
	size_t			elems;

	elems = 0;
	if (v && val && val_sz == v->type_sz)
	{
		elems = v->type_sz * v->size;
		if (v->capacity < v->size + 1)
			ft_vresize(v, v->capacity * v->type_sz * 2);
		tmp = (unsigned char*)v->data;
		ft_memmove((void*)&tmp[v->size * v->type_sz], val, val_sz);
		v->size += 1;
	}
}
