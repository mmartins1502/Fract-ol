# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmartins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/19 16:06:00 by mmartins          #+#    #+#              #
#    Updated: 2016/12/01 11:40:20 by mmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = ft_strlen.c ft_strdup.c  ft_strcpy.c ft_putchar.c ft_putstr.c \
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	  ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl.c \
	  ft_putendl_fd.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	  ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	  ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_lstpushback.c \
	  drawline.c image.c mlx.c get_next_line.c ft_stradd.c \
	  ft_printf/conv_int.c \
		ft_printf/flag.c \
		ft_printf/ft_printf.c \
		ft_printf/conv_uint.c \
		ft_printf/conv_str.c \
		ft_printf/conv_char.c \
		ft_printf/conv_wchar.c \
		ft_printf/ft_wctomb.c \
		ft_printf/ft_uitoa.c \
		ft_printf/ft_isdigit.c \
		ft_printf/ft_memalloc.c \
		ft_printf/ft_memset.c \
		ft_printf/ft_strnew.c \
		ft_printf/ft_atoi.c \
		ft_printf/ft_memcpy.c \
		ft_printf/ft_putnstr.c \
		ft_printf/ft_strlen.c \
		ft_printf/ft_uitoa_base.c \
		ft_printf/conv_pointer.c \
		ft_printf/conv_wstr.c \
		ft_printf/ft_br_isconv_notflag.c \
		ft_printf/ft_width_prec_resetflag.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

$(OBJ):
		@$(CC) $(FLAGS) -c $*.c -o $@ -I includes

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
