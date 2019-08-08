/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 00:36:42 by chermist          #+#    #+#             */
/*   Updated: 2019/08/09 01:57:23 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	ft_vresize(t_vector *v, size_t size)
{
	void	*new;

	if (v && size)	
		v->data = ft_realloc(v-data, v->size, size);
}
