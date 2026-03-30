GREEN       = \033[0;32m
RED         = \033[0;31m
BLUE        = \033[0;34m
YELLOW      = \033[0;33m
RESET       = \033[0m
NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
INCLUDES    = -I.
RM          = rm -rf

SRCS        = main.c \
              srcs/parsing/parsing_2.c \
              srcs/parsing/validate.c \
              srcs/parsing/atoi.c \
              srcs/parsing/flags.c \
              srcs/parsing/split.c \
              srcs/parsing/indexing.c \
              srcs/stack/stack_init.c \
              srcs/stack/stack_check.c \
              srcs/stack/stack_find.c \
              srcs/stack/stack_utils.c \
              srcs/stack/stack_free.c \
              srcs/operations/swap.c \
              srcs/operations/push.c \
              srcs/operations/rotate.c \
              srcs/operations/reverse_rotate.c \
              srcs/algorithms/simple_algo.c \
              srcs/algorithms/adaptive_algo.c \
              srcs/algorithms/medium_algo.c \
              srcs/radix/radix.c \
              srcs/chunk/chunk_main.c \
              srcs/chunk/chunk_merge.c \
              srcs/turk+LIS/turk_main.c \
              srcs/turk+LIS/turk_list.c \
              srcs/turk+LIS/turk_positions.c \
              srcs/turk+LIS/turk_costs.c \
              srcs/turk+LIS/turk_execute.c \
              srcs/benchmark/benchmark_init.c \
              srcs/benchmark/benchmark_print.c \
              srcs/utils/utils.c \
              srcs/utils/error.c \
              srcs/utils/structure.c

OBJS        = $(SRCS:.c=.o)
DEPS        = $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

test: $(NAME)
	@echo "$(BLUE)Testing with 3 numbers...$(RESET)"
	@./$(NAME) 2 1 3
	@echo ""
	@echo "$(BLUE)Testing with 100 numbers...$(RESET)"
	@ARG=$$(gshuf -i 0-999 -n 100 | tr '\n' ' '); \
	    ./$(NAME) --simple $$ARG | wc -l

test-bench: $(NAME)
	@echo "$(BLUE)Testing benchmark mode with 100 numbers...$(RESET)"
	@ARG=$$(gshuf -i 0-999 -n 100 | tr '\n' ' '); \
	    ./$(NAME) --bench --adaptive $$ARG 2>&1

.PHONY: all clean fclean re test test-bench

-include $(DEPS)