NAME	= checker
LIB		= checker.a
CREATE	= ar -rcs
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I../include
RM		= rm -f
LIB_PS	= -L../ -l:push_swap.a -L../libft -l:libft.a
SRCS 	= main_bonus.c utils_checker.c
OBJS 	= ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${LIB}
	${CC} ${CFLAGS} ${OBJS} ${LIB_PS} -o $@
	cp ${NAME} ../

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${LIB}: ${OBJS}
	${CREATE} ${LIB} $^
	
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${LIB}

re: fclean all

.PHONY: all clean fclean re

