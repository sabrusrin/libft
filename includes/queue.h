/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:48:19 by chermist          #+#    #+#             */
/*   Updated: 2019/09/19 00:40:49 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "libft.h"

typedef struct	s_queue
{
	void		*data;
	int			front;
	int			rear;
	size_t		elems;
	size_t		size;
	size_t		capacity;
	size_t		type_sz;
}				t_queue;

t_queue			*ft_qnew(size_t	capacity, size_t type_sz);
void			ft_qpush(t_queue *queue, void *item);
void			*ft_qpop(t_queue *queue);
void			*ft_qat(t_queue *q, size_t at);
void			*ft_qback(t_queue *queue);
void			*ft_qfront(t_queue *queue);
int				ft_qempty(t_queue *queue);
int				ft_qfull(t_queue *queue);
size_t			ft_qsize(t_queue *queue);
void			ft_qclear(t_queue *q);
void			ft_qdel(t_queue **q);

#endif
