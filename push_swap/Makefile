NAME		= push_swap
LIB			= push_swap.a
CREATE		= ar -rcs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I./include
RM			= rm -f
LIBFT		= libft
CHECKER		= bonus
SRCS		= srcs/check_av.c \
				srcs/finders.c \
				srcs/ft_atol.c \
				srcs/handle_error.c \
				srcs/hard_sort.c \
				srcs/init_stack.c \
				srcs/main.c \
				srcs/move_nodes.c \
				srcs/push_node.c \
				srcs/rev_rotate_stack.c \
				srcs/rotate_stack.c \
				srcs/set_nodes.c \
				srcs/simple_sort.c \
				srcs/swap_node.c \
				srcs/utils.c 

OBJS		=${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${LIB}
	make -C ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} -L${LIBFT} -lft -o $@

${LIB}: ${OBJS}
	${CREATE} ${LIB} $^

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

bonus:
	make -C ${CHECKER}

clean:
	make clean -C ${LIBFT}
	make clean -C ${CHECKER}
	${RM} ${OBJS}

fclean: clean
	make fclean -C ${LIBFT}
	make fclean -C ${CHECKER}
	${RM} ${LIB}

re: fclean all


.PHONY: all bonus clean fclean re
