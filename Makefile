# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 18:25:22 by adben-mc          #+#    #+#              #
#    Updated: 2021/12/06 18:41:59 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c \
			get_next_line_utils.c

SRCSBONUS =	get_next_line_bonus.c \
			get_next_line_utils_bonus.c

OBJS	= 	${SRCS:.c=.o}

OBJSBON	= 	${SRCSBONUS:.c=.o}

NAME	= 	libft.a

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar -rcs $(NAME) $(OBJS)

all:		${NAME}

clean:
			${RM} ${OBJSBON} ${OBJS}

fclean:		clean
			${RM} ${NAME} 

bonus:		${OBJSBON}
			ar -rcs $(NAME) ${OBJSBON}

re:			fclean all

.PHONY:		bonus all clean fclean re