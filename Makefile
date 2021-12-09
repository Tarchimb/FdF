# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 11:24:39 by tarchimb          #+#    #+#              #
#    Updated: 2021/12/09 12:09:26 by tarchimb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_parsing.c				\
				ft_parsing_2.c				\
				ft_window.c					\
				ft_convert_map_to_iso.c		\
				ft_hooks.c					\

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	Includes/fdf.h				\
				Includes/libft.h			\
				Minilibx/mlx.h				\

LIBINCLUDES	=	-IIncludes -IMinilibx

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror -g 

NAME		=	./libfdf.a

MLXFLAGS 	=	-framework OpenGL -framework AppKit

LIBS 		= 	./libmlx.dylib				\
				./libft.a					\
				${NAME}						\
			

RM			=	rm -f

all:		${NAME}

%.o:		%.c ${INCLUDES}
			${CC} ${CFLAGS} ${LIBINCLUDES} -c $< -o $@

gc:			${LIBS}
			${CC} ${CFLAGS} ${MLXFLAGS} ${LIBS} ${LIBINCLUDES} main.c -o fdf
			leaks -atExit -- ./fdf

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
			@${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re