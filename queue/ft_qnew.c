/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:47:02 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 19:17:30 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_q	*ft_qnew(size_t capacity, size_t type_sz)
{
	t_q *queue;

	if ((queue = (t_q*)malloc(sizeof(t_q))))
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
