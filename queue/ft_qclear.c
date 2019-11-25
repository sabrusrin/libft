/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 01:50:04 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 19:16:39 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qclear(t_q *q)
{
	if (q)
	{
		if (q->data)
			ft_memdel(&q->data);
		q->elems = 0;
		q->size = 0;
		q->front = 0;
		q->rear = q->capacity - 1;
	}
}
