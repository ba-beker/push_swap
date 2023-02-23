# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 17:10:59 by mobabeke          #+#    #+#              #
#    Updated: 2023/02/17 18:01:53 by mobabeke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = push_swap

# SRC = $(wildcard utils/*.c src/*.c)

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# all: ${NAME}
# ${NAME}: ${OBJS}
# 	@${MAKE} -C ./libft
# 	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	
# clean:
# 	@${MAKE} -C ./libft fclean
# 	@${RM} ${OBJS}

# fclean: clean
# 	@${RM} ${NAME}
	
# re: fclean all

# .PHONY: all clean fclean re
NAME = push_swap
CHECK = checker

SRCS =  $(wildcard src/*.c utils/*.c)
CHECK_SRCS = $(wildcard utils/*.c) src/operations_rotate.c src/operations_push.c src/operations_reverse_rotate.c src/operations_swap.c checker.c

OBJS = ${SRCS:.c=.o}
CHECK_OBJS = ${CHECK_SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME} ${CHECK}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

${CHECK}: ${CHECK_OBJS} 
	@${CC} ${CFLAGS} ${CHECK_OBJS} ./libft/libft.a -o ${CHECK}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@${RM} ${CHECK_OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${CHECK}

re: fclean all

.PHONY: all clean fclean re
