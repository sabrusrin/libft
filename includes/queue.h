/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:48:19 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 19:11:52 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

/*
**A structure to represent a queue
**Structure parameters:
**	data - stores a queue elements.
**	front - first element position.
**	rear - position of last element.
**	elems - number of elements.
**	size - number of elements in the queue.
**	capacity - capacity of the queue.
**	type_sz - type size of the elements.
*/
typedef struct	s_q
{
	void		*data;
	int			front;
	int			rear;
	size_t		elems;
	size_t		size;
	size_t		capacity;
	size_t		type_sz;
}				t_q;

/*
**ft_qnew - Creates a new queue and allocates memory for <capacity> number of
**elemenst with <type_sz> size. Returns a pointer to created vector.
**	Example:
**	t_q *queue;
**	queue = ft_qnew(10, sizeof(int));
**	allocates memory for a queue of 10 integers
*/
t_q				*ft_qnew(size_t	capacity, size_t type_sz);
/*
**ft_qpush - The element <item> added to the back of the queue.
*/
void			ft_qpush(t_q *queue, void *item);
/*
**ft_qpop - Removes an element from the front of the queue.
*/
void			*ft_qpop(t_q *queue);
/*
**ft_qat - Returns a pointer to the element at a specified location.
*/
void			*ft_qat(t_q *q, size_t at);
/*
**ft_qback - Returns a pointer to the last element in the queue.
*/
void			*ft_qback(t_q *queue);
/*
**ft_qfront - Returns a pointer to the first element in the queue.
*/
void			*ft_qfront(t_q *queue);
/*
**ft_qempty - Tests if the queue is empty.
**Returns 1 if the queue is empty; 0 if the queue is nonempty.
*/
int				ft_qempty(t_q *queue);
/*
**ft_qfull - Tests if the queue is full.
*/
int				ft_qfull(t_q *queue);
/*
**ft_qsize - Returns a queue size.
*/
size_t			ft_qsize(t_q *queue);
/*
**ft_qclear - Erases the elements of the queue and sets default parameters
*/
void			ft_qclear(t_q *q);
/*
**ft_qdel - Deletes queue.
*/
void			ft_qdel(t_q **q);

#endif
