# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:40:37 by malouvar          #+#    #+#              #
#    Updated: 2022/01/12 10:41:26 by malouvar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		parsing.c \
		parsing_cartesian.c \
		parsing_iso.c \
		draw_fdf.c \
		mlx_functions.c \
		free_struct.c

OBJS = ${SRCS:.c=.o}


NAME = fdf

MINILIBX = mlx_Linux

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MINILIBX = mlx_Linux

RM = rm -f

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(MINILIBX) $(OBJS)
	@${MAKE} -C libft
	@echo "fdf : libft compiled."
	@${CC} -g ${FLAGS} -o ${NAME} ${OBJS} libft/libft.a -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
	@echo "fdf : compiled."

$(MINILIBX):
		cd ./minilibx-linux && ./configure
		@echo "fdf : minilibx configured."
clean:
			@${MAKE} -C libft clean
			@${RM} ${OBJS}
			@echo "fdf : \".o\" files were erased"

fclean:		clean
			@${MAKE} -C libft fclean
			@${RM} ${NAME}
			@echo "fdf : \".o\" and executables were erased"

re: fclean all

.PHONY:		bonus all clean fclean re
