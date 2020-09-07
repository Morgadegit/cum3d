# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraphard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 20:07:37 by sraphard          #+#    #+#              #
#    Updated: 2020/09/07 13:46:20 by sraphard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strcat.c ft_atoi.c ft_isdigit.c ft_memcpy.c ft_putstr_fd.c ft_strlcpy.c ft_strtrim.c ft_bzero.c ft_isprint.c ft_memmove.c ft_split.c ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_itoa_uns.c ft_memset.c ft_strchr.c ft_strmapi.c ft_tolower.c ft_isalnum.c ft_memccpy.c ft_putchar_fd.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memchr.c  ft_putendl_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c ft_memcmp.c  ft_putnbr_fd.c ft_strlcat.c ft_strrchr.c ft_get_size_number.c ft_revert_array.c ft_dec_to_binary_convert.c ft_strcmp.c ft_dec_to_binary_32bits_convert.c ft_binary_to_hex_convert.c ft_dec_to_hex_convert.c ft_power.c ft_put_unsigned_fd.c ft_abs.c ft_get_size_unsigned.c ft_strncat.c ft_delchar.c ft_strnjoin.c ft_add_x_char.c ft_nbrlen.c ft_strrep.c ft_iswhite.c ft_is_set_nbr.c ft_is_btwn.c ft_strndup.c ft_strlstr.c

SRCS_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS		=	${SRCS:.c=.o}

OBJSB		=	${SRCS_BONUS:.c=.o}

FLAGS		=	-Wall -Wextra -Werror

NAME		=	libft.a

RM			=	rm -rf

all			:	${NAME}

$(NAME)		:	${OBJS}
				ar rc ${NAME} ${OBJS} 
				ranlib ${NAME}

.c.o		:
				gcc ${FLAGS} -c $< -o ${<:.c=.o}

bonus		:	$(OBJS) ${OBJSB}
				ar rc ${NAME} ${OBJSB} 
				ranlib ${NAME}

clean		:
				${RM} ${OBJS}

cleanb		:
				${RM} ${OBJSB} ${OBJS}

fclean		:	clean
				${RM} ${NAME}

fcleanb		:	cleanb
				${RM} ${NAME}

re			:	fclean all

allc		:	all clean

bonusc		:	bonus cleanb

rec			:	re clean
