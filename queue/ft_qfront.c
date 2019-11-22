/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qfront.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:55:11 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 19:17:17 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_qfront(t_q *queue)
{
	if (ft_qempty(queue))
		return (NULL);
	return ((void*)&queue->data[queue->front * queue->type_sz]);
}
