/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:51:46 by chermist          #+#    #+#             */
/*   Updated: 2019/08/09 17:25:02 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"vector.h"

t_vector	*ft_vnew(size_t size, size_t type_sz)
{
	t_vector	*v;

	v = NULL;
	if (size && type_sz && (v = (t_vector *)malloc(sizeof(t_vector))))
	{
		v->type_sz = type_sz;
		v->size = size;
		if (!(v->data = malloc(size)))
			ft_memdel((void**)&v);
	}
	return (v);
}
