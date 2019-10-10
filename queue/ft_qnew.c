/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:47:02 by chermist          #+#    #+#             */
/*   Updated: 2019/09/20 02:15:40 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*ft_qnew(size_t capacity, size_t type_sz)
{
	t_queue *queue;

	if ((queue = (t_queue*)malloc(sizeof(t_queue))))
	{
		queue->capacity = capacity;
		queue->type_sz = type_sz;
		queue->elems = 0;
		queue->size = 0;
		queue->front = 0;
		queue->rear = capacity - 1;
		if (!(queue->data = malloc(type_sz * capacity)))
			ft_memdel((void**)&queue);
	}
	return (queue);
}
