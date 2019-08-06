# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chermist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/27 22:25:22 by chermist          #+#    #+#              #
#    Updated: 2019/08/06 19:22:22 by chermist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MEM_F = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_arrdel.c \
		ft_realloc.c \

STR_F = ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_wcount.c

CHR_F = ft_atoi.c \
		ft_itoa.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_toupper.c \
		ft_tolower.c

PUT_F = ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

LST_F =	ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstmap.c \
		ft_lstiter.c \
		ft_lstappend.c

MATH_F = ft_pow.c \
		 ft_sqrt.c \
		 ft_fabs.c


MY_F  = get_next_line.c

SRCS =	$(MEM_F) $(STR_F) $(CHR_F) $(PUT_F) $(LST_F) $(MY_F) $(MATH_F)

INC = -I./includes

OBJ = $(SRCS:%.c=%.o)

vpath %.c memory
vpath %.c string
vpath %.c char
vpath %.c print
vpath %.c utils
vpath %.c lst
vpath %.c myfunc
vpath %.c math

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) $(INC) -c $< -o $@


clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
