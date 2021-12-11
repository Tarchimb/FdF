# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 11:24:39 by tarchimb          #+#    #+#              #
#    Updated: 2021/12/11 09:05:17 by tarchimb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/ft_parsing.c				\
				srcs/ft_parsing_2.c				\
				srcs/ft_window.c				\
				srcs/ft_convert_map_to_iso.c	\
				srcs/ft_hooks.c					\

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	Includes/fdf.h				\
				Includes/libft.h			\
				Minilibx/mlx.h				\

LIBINCLUDES	=	-IIncludes -IMinilibx

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror -g -fsanitize=address

NAME		=	./libfdf.a

MLXFLAGS 	=	-framework OpenGL -framework AppKit

LIBS 		= 	./libmlx.dylib				\
				./libft.a					\
				${NAME}						\
			

RM			=	rm -rf

all:		${NAME} gc

%.o:		%.c ${INCLUDES}
			${CC} ${CFLAGS} ${LIBINCLUDES} -c $< -o $@

gc:			${LIBS}
			${CC} ${CFLAGS} ${MLXFLAGS} ${LIBS} ${LIBINCLUDES} fdf.c -o fdf

$(NAME):	${OBJS} ${INCLUDES}
			make -C ./Minilibx
			make -C ./Libft	
			ar rcs ${NAME} ${OBJS}

clean:
			@${RM} ${OBJS} ${OBJSBONUS}
			make clean -C ./Minilibx	
			make clean -C ./Libft

			
fclean:		clean
			make fclean -C ./Libft
			@${RM} ${LIBS}

re:			fclean all

.PHONY: 	all clean fclean re