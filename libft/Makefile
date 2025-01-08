SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
          ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
          ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
          ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
          ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
          ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
          ft_split.c ft_strmapi.c ft_striteri.c ft_strtrim.c ft_itoa.c \
          get_next_line.c ft_printf.c ft_atoi_printf.c ft_specifier_utils.c \
          ft_handle_format.c ft_itoa_printf.c ft_print_char.c \
          ft_print_str.c ft_printf_utils.c ft_uitoa.c ft_ultoa.c

# Fichiers objets
OBJS_PATH = ./objs/
OBJS = $(patsubst %.c, ${OBJS_PATH}%.o, ${SOURCES})

# Compilation
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./

# Règles
all : ${NAME}

${OBJS_PATH}%.o : %.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c -o $@ $< -I${HEADER}

${NAME} : ${OBJS}
	ar -rsc ${NAME} ${OBJS}
	echo "\033[1mLIBFT COMPILATION COMPLETE\033[0m"

clean :
	rm -f ${OBJS}
	rm -rf ${OBJS_PATH}

fclean : clean
	rm -f ${NAME}

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus
