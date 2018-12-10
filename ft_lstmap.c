/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:23:45 by chermist          #+#    #+#             */
/*   Updated: 2018/12/07 17:05:29 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_del(void *content, size_t content_size)
{
	if (content)
		free(content);
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*begin;

	if (!lst || !f || !(new = f(lst)))
		return (NULL);
	begin = new;
	while ((lst = lst->next))
	{
		if (!(tmp = f(lst)))
		{
			ft_lstdel(&begin, &ft_del);
			return (NULL);
		}
		else
		{
			new->next = tmp;
			new = new->next;
		}
	}
	return (begin);
}
