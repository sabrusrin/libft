/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:55:34 by chermist          #+#    #+#             */
/*   Updated: 2019/09/19 00:37:50 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*ft_qback(t_queue *queue)
{
	if (ft_qempty(queue))
		return (NULL);
	return ((void*)&queue->data[queue->rear * queue->type_sz]);
}
