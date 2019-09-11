/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vresize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 17:21:12 by chermist          #+#    #+#             */
/*   Updated: 2019/09/11 15:27:35 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	ft_vresize(t_vec *v, size_t size)
{
	if (v && size)
		if ((v->data = ft_realloc(v->data, v->capacity * v->type_sz, size)))
			v->capacity = size / v->type_sz;
}
