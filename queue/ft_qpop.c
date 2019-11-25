/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:15:08 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 19:17:48 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
