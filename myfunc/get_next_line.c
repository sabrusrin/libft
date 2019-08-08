/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:29:09 by chermist          #+#    #+#             */
/*   Updated: 2019/08/09 01:29:22 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*check_fd(t_line *curr_l, int fd)
{
	t_line	*tmp;
	t_line	*prev;

	tmp = curr_l;
	prev = NULL;
	while (curr_l && curr_l->fd != fd)
	{
		prev = curr_l;
		curr_l = curr_l->next;
	}
	if (!curr_l)
	{
		if (!(curr_l = malloc(sizeof(t_line))))
			return (NULL);
		if (!(curr_l->con = malloc(0)))
			return (NULL);
		curr_l->fd = fd;
		curr_l->c_sz = 0;
		curr_l->next = NULL;
	}
	if (prev)
		prev->next = curr_l->next;
	if (curr_l != tmp)
		curr_l->next = tmp;
	return (curr_l);
}

char	*join_n_free(char **s1, char const *s2, int cen, int nb)
{
	char	*tmp;

	if (!s1 || !(*s1) || !s2)
		return (NULL);
	if (cen > 0)
	{
		if (!(*s1 = ft_realloc((void**)s1, cen, cen + nb)))
			return (NULL);
	}
	else
	{
		free(*s1);
		if (!(*s1 = malloc(nb)))
			return (NULL);
	}
	tmp = *s1;
	*s1 += cen;
	while (nb--)
		*(*s1++) = *s2++;
	return (tmp);
}

int		copy_til(char **dst, char *src, char c, int nb)
{
	size_t	i;
	char	*tmp;

	tmp = src;
	i = 0;
	while (nb-- && ++i && *tmp != c)
		tmp++;
	if (!(*dst = malloc((nb < 0) ? (i + 1) : i)))
		return (-1);
	ft_memcpy(*dst, src, i);
	if (nb < 0)
		i[*dst] = 0;
	else
		(i - 1)[*dst] = 0;
	return (i);
}

int		copy_del(t_line **curr_l, char **line)
{
	t_line	*tmp;
	ssize_t	rb;

	tmp = NULL;
	if ((rb = copy_til(line, (*curr_l)->con, '\n', (*curr_l)->c_sz)) == -1)
		return (1);
	if (rb < (*curr_l)->c_sz)
	{
		ft_memmove((*curr_l)->con, &((*curr_l)->con)[rb], (*curr_l)->c_sz - rb);
		if (!((*curr_l)->con = ft_realloc((*curr_l)->con,
			(*curr_l)->c_sz, (*curr_l)->c_sz - rb)))
			return (1);
		(*curr_l)->c_sz = (*curr_l)->c_sz - rb;
	}
	else
	{
		tmp = (*curr_l);
		(*curr_l) = (*curr_l)->next;
		free(tmp->con);
		tmp->fd = 0;
		tmp->c_sz = 0;
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE];
	static t_line	*curr_l = NULL;
	size_t			rb;

	if ((!line || fd < 0 || BUFF_SIZE < 1 || read(fd, 0, 0) < 0
		|| !(curr_l = check_fd(curr_l, fd))))
		return (-1);
	while ((rb = read(fd, buffer, BUFF_SIZE)))
	{
		if (!(curr_l->con = join_n_free((char**)&curr_l->con, buffer, curr_l->c_sz, rb)))
			return (-1);
		if ((curr_l->c_sz += rb) && (ft_strchr(buffer, '\n')))
			break ;
	}
	if (!rb && !curr_l->c_sz)
		return (0);
	if (copy_del(&curr_l, line))
		return (-1);
	return (1);
}
