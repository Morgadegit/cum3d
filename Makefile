# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraphard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 13:41:19 by sraphard          #+#    #+#              #
#    Updated: 2020/09/22 13:42:26 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS            =       gnl/get_next_line.c \
			$(wildcard parsing/*.c) \
			$(wildcard libft/*.c) \
			$(wildcard *.c) \

OBJS            =	${SRCS:.c=.o}

FLAGS		=	-Wall -Wextra -Werror

NAME		=	cub3d

LIBS		=	-lX11 -lXext -std=gnu99 -Wl,--start-group mlx/libmlx.a mlx/libmlx_Linux.a -Wl,--end-group -lm

RM		=	rm -rf

all		:	${NAME}

cub3d.a		:	${OBJS}	
			ar rcs cub3d.a ${OBJS}
			ranlib cub3d.a

$(NAME)		:	cub3d.a
			gcc -o ${NAME} cub3d.c cub3d.a -I. -g ${LIBS}

.c.o		:
			gcc -c $< -o ${<:.c=.o}

clean		:
			${RM} ${OBJS}

fclean		:	clean
			${RM} ${NAME}

re		:	fclean all

allc		:	all clean
			make -C libft/ clean

rec		:	re clean

