/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:25:09 by chermist          #+#    #+#             */
/*   Updated: 2019/11/21 19:11:55 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1

typedef struct		s_line
{
	int				fd;
	void			*con;
	ssize_t			c_sz;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
