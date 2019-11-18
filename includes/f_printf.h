/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:12:45 by chermist          #+#    #+#             */
/*   Updated: 2019/11/18 17:46:05 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_PRINTF_H
# define F_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

#define LENGTH "lLhjz"
#define TYPE "dDioOuUxXfFeEcCsSpaAgGpb"
#define FLAGS "#0- +'"

typedef struct	s_pf
{
	char		hash;
	char		zero;
	char		minus;
	char		space;
	char		plus;
	int			width;
	int			preci;
}				t_pf;

void			parse_format(va_list ap, const char *format, t_vec *buf, \
																	t_pf *sup);
void			set_default(t_pf *sup);

#endif
