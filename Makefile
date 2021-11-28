# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 11:24:39 by tarchimb          #+#    #+#              #
#    Updated: 2021/11/26 14:07:10 by tarchimb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	./main.c							\
				./Libft/ft_atoi.c ./Libft/ft_calloc.c ./Libft/ft_isalpha.c ./Libft/ft_isdigit.c \
      			./Libft/ft_memcmp.c ./Libft/ft_memmove.c ./Libft/ft_putchar_fd.c\
				./Libft/ft_split.c ./Libft/ft_strdup.c ./Libft/ft_strjoin.c ./Libft/ft_strlcpy.c \
				./Libft/ft_strmapi.c ./Libft/ft_strnstr.c ./Libft/ft_strtrim.c ./Libft/ft_tolower.c \
				./Libft/ft_bzero.c ./Libft/ft_isalnum.c ./Libft/ft_isascii.c ./Libft/ft_isprint.c \
				./Libft/ft_memchr.c ./Libft/ft_memcpy.c ./Libft/ft_memset.c ./Libft/ft_putendl_fd.c \
				./Libft/ft_putstr_fd.c ./Libft/ft_strchr.c ./Libft/ft_striteri.c \
				./Libft/ft_strlen.c ./Libft/ft_strncmp.c ./Libft/ft_strrchr.c ./Libft/ft_substr.c \
				./Libft/ft_toupper.c ./Libft/ft_itoa.c ./Libft/ft_putnbr_fd.c ./Libft/ft_strlcat.c\
				./Libft/get_next_line.c ./Libft/get_next_line_utils.c \					\

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	./Includes/fdf.h					\
				./Includes/libft.h					\
				./Minilibx/mlx.h					\

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

NAME		=	./fdf.a

RM			=	rm -f

all:		${NAME}

%.o:		%.c ${INCLUDES}
			${CC} ${CFLAGS} -I ./Includes -c $< -o $@

$(NAME):	${OBJS} ${INCLUDES}
			make -C ./Minilibx
			ar rcs ${NAME} ${OBJS}

clean:
			@${RM} ${OBJS} ${OBJSBONUS}
			make clean -C ./Minilibx

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
