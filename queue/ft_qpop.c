/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:15:08 by chermist          #+#    #+#             */
/*   Updated: 2019/11/16 20:17:01 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*ft_qpop(t_q *queue)
{
	void	*item;

	if (ft_qempty(queue))
		return (NULL);
	item = (void*)&queue->data[queue->front * queue->type_sz];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size -= 1;
	return (item);
}
