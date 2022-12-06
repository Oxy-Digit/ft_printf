NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c\
		ft_len_of_d.c ft_len_of_u.c\
		ft_putstr.c ft_len_of_x.c\
		ft_len_of_x_big.c ft_len_of_p.c

HEADER = ft_printf.h

OBJS = $(SRCS:%.c=%.o)
	
CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.PNONY: all clean fclean re

all: 	${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} $?

%.o: %.c ${HEADER} Makefile
	${CC} ${CFLAGS} -c $< -o $@

clean: 
		${RM} ${OBJS}

fclean: clean 
		${RM} ${NAME}

re: fclean all
