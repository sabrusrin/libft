/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:50:29 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 19:14:52 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_vdup(t_vec *vsrc)
{
	t_vec	*vdst;

	if ((vdst = ft_vnew(vsrc->capacity, vsrc->type_sz)))
	{
		ft_memmove(vdst->data, vsrc->data, vsrc->size * vsrc->type_sz);
		vdst->size = vsrc->size;
		return (vdst);
	}
	return (NULL);
}
