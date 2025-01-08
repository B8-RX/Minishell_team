# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssghioua <ssghioua@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 02:51:28 by ssghioua          #+#    #+#              #
#    Updated: 2025/01/08 02:51:37 by ssghioua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT_LIB = ${LIBFT_DIR}/libft.a
INCLUDES = -I./includes -I${LIBFT_DIR} -I.
SRCS = $(shell find ./src -name '*.c')
OBJS = $(SRCS:./src/%.c=./obj/%.o)
OBJS_DIR = ./obj

all: ${NAME}

${NAME}: ${LIBFT_LIB} ${OBJS}
	@echo "Linking ${NAME}..."
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_LIB} -lreadline
	@echo "\033[1mCompilation de MINISHELL terminée !\033[0m"

${LIBFT_LIB}:
	@echo "Compilation de libft..."
	@make -C ${LIBFT_DIR}

./obj/%.o: ./src/%.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	@echo "Nettoyage des fichiers objets..."
	@rm -rf ${OBJS_DIR}
	@make -C ${LIBFT_DIR} clean

fclean: clean
	@echo "Nettoyage complet..."
	@rm -f ${NAME}
	@make -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re
