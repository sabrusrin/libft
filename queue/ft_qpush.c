/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:15:12 by chermist          #+#    #+#             */
/*   Updated: 2019/09/20 17:17:11 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

void	ft_qpush(t_queue *q, void *item)
{
	if (ft_qfull(q))
		return ;
	q->rear = (q->rear + 1) % q->capacity;
	ft_memmove((void*)&q->data[q->rear * q->type_sz],
			item, q->type_sz);
	q->elems += 1;
	q->size += 1;
}
