# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraphard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 13:41:19 by sraphard          #+#    #+#              #
#    Updated: 2020/09/10 14:03:42 by sraphard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS            =       gnl/get_next_line.c \
			cub3d.c cub3d_utils.c \
			check_line.c map_parsing.c \

OBJS            =	${SRCS:.c=.o}

FLAGS		=	-Wall -Wextra -Werror -g

NAME		=	cub3d.a

RM		=	rm -rf

all		:	${NAME}

$(NAME)		:	${OBJS}	
				ar rcs ${NAME} ${OBJS}
				ranlib ${NAME}

.c.o		:
				gcc ${FLAGS} -c $< -o ${<:.c=.o}

clean		:
				${RM} ${OBJS}

fclean		:	clean
				${RM} ${NAME}

re		:	fclean all

allc		:	all clean
				make -C libft/ clean

rec		:	re clean

