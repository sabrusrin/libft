/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chermist <chermist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:16:57 by lkarlon-          #+#    #+#             */
/*   Updated: 2019/10/11 00:21:36 by chermist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define SPCFR(x) (ft_strchr("dDioOuUxXfFeEcCsSpaAgGpb", x))
# define FLAGS(x) (ft_strchr("-+ #0", x))
# define MDFR(x) (ft_strchr("lLhjz", x) != NULL)
# define ALLSHT(x) (ft_strchr("dDioOuUxXfFeEcCsSpaAgGpb-+ #0lLhjz.%", x))
# define ALLMDFR(x) (ft_strchr("-+ #0lLhjz.*0123456789", x))

typedef struct	s_mdfrs
{
	char		*pbuffer;
	char		flag[7];
	int			modifier;
	int			width;
	int			pr;
	char		spec;
	int			c_num;
}				t_mdfrs;

int				ft_printf(const char *format, ...);
size_t			parse(const char *format, va_list ap);
size_t			spec_exe(char *spec, va_list ap, t_mdfrs *mods);
void			pf_putchar(int c, t_mdfrs *m);
void			pf_putstr(char	*s, t_mdfrs *m);
void			pf_putnbr(long long n, t_mdfrs *m);
void			u_pf_putnbr(unsigned long long n, t_mdfrs *m);
void			pf_putdbl(long double d, t_mdfrs *m);
void			pf_base(uintmax_t num, t_mdfrs *m);
void			pf_base(uintmax_t num, t_mdfrs *m);
void			do_width(t_mdfrs *m, char f);
void			do_hash(t_mdfrs *m, int f);
void			do_preci(t_mdfrs *m, long double dpart, char c);
void			nbr_preci(t_mdfrs *m, long long *n, char *sign);
void			nbr_sign(t_mdfrs *m, char *sign, long long *n, char *p);
void			type_parse(va_list ap, t_mdfrs *m, char flag);
void			clean_mods(t_mdfrs *m);
int				count_num(long long i);
void			x_type_parse(va_list ap, t_mdfrs *m);
void			u_type_parse(va_list ap, t_mdfrs *m);
void			d_type_parse(va_list ap, t_mdfrs *m);
void			u_ft_putnbr(unsigned long long n);
int				u_count_num(unsigned long long i);
int				more_bytes_putchar(int c);
void			l_pf_putstr(int *s, t_mdfrs *m);
int				count_utf_bytes(int c);

#endif
