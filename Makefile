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

SRCS		=	main.c							\
				Libft/*.c						\

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	Includes/fdf.h					\
				Includes/libft.h				\
				Minilibx/mlx.h					\

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
