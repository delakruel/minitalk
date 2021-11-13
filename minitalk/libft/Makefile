# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rloyce <rloyce@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 16:05:18 by rloyce            #+#    #+#              #
#    Updated: 2021/04/21 14:42:06 by rloyce           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

INCLUDE		=	libft.h

LIST		=	ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
			ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
			ft_tolower.c ft_memset.c ft_calloc.c ft_strdup.c ft_bzero.c \
			ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

LIST_B		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ			=	$(patsubst %.c,%.o,$(LIST))
OBJ_B		=	$(patsubst %.c,%.o,$(LIST_B))

CFLAGS		=	-Wall -Wextra -Werror

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) libft.h
	ar rcs $(NAME) $(OBJ)

bonus :
	@make OBJ="$(OBJ_B)" all

clean :
	@rm -f $(OBJ) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
