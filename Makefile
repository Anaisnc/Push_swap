NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = main.c \
	   srcs/parsing/parsing_2.c \
	   srcs/parsing/validate.c \
	   srcs/parsing/atoi.c \
	   srcs/parsing/flags.c \
	   srcs/parsing/indexing.c \
	   srcs/stack/stack_init.c \
	   srcs/stack/stack_check.c \
	   srcs/stack/stack_find.c \
	   srcs/stack/stack_utils.c \
	   srcs/operations/swap.c \
	   srcs/operations/push.c \
	   srcs/operations/rotate.c \
	   srcs/operations/reverse_rotate.c \
	   srcs/algorithms/simple_algo.c \
	   srcs/turk+LIS/turk_main.c \
	   srcs/turk+LIS/turk_list.c \
	   srcs/turk+LIS/turk_positions.c \
	   srcs/turk+LIS/turk_costs.c \
	   srcs/turk+LIS/turk_execute.c \
	   srcs/utils/utils.c \
	   srcs/utils/error.c \
	   srcs/utils/structure.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re