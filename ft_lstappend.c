/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstapp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 23:47:52 by chermist          #+#    #+#             */
/*   Updated: 2018/12/08 14:41:19 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list *alst, t_list *new)
{
	t_list	*cur;

	if (alst && new)
	{
		cur = alst;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
		new->next = NULL;
	}
}
