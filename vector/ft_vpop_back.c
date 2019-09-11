/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpop_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:44:42 by chermist          #+#    #+#             */
/*   Updated: 2019/09/11 15:27:59 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	ft_vpop_back(t_vec *v)
{
	void			*addr;
	unsigned char	*tmp;

	addr = NULL;
	if (v && v->size)
	{
		tmp = (unsigned char*)v->data;
		addr = (void*)&tmp[v->size * v->type_sz - v->type_sz];
		ft_memset(addr, 0, v->type_sz);
		v->size -= 1;
	}
}
