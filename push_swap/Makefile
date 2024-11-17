NAME = push_swap
CHECKER = checker

LIBFT_DIR = ./lib/libft
PRINTF_DIR = ./lib/printf
GNL_DIR = ./lib/gnl
PUSHSWAP_DIR = ./srcs
CHECKER_DIR = ./checker_srcs
OBJS_DIR = ./objs
PUSHSWAP_OBJS_DIR = $(OBJS_DIR)/push_swap
CHECKER_OBJS_DIR = $(OBJS_DIR)/checker

FT_PRINTF = ./lib/printf/libftprintf.a -L$(PRINTF_DIR) -lftprintf
GNL = ./lib/gnl/get_next_line.a

SRCS = main\
		atoi\
		make_stacks\
		make_stacks_ii\
		actions/push\
		actions/swap\
		actions/rotate\
		actions/rev_rotate\
		lst_utils\
		commands\
		delete_commands\
		merge_commands\
		sort_few\
		sort_many\
		divide\
		divide_utils\
		combine\
		combine_utils
CHECKER_SRCS = main\
			get_inputs\
			atoi\
			push_swap\
			rotations\
			exit

OBJS = $(foreach src,$(SRCS), $(PUSHSWAP_OBJS_DIR)/$(src).o)
CHECKER_OBJS = $(foreach src, $(CHECKER_SRCS),$(CHECKER_OBJS_DIR)/$(src).o)

CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes/

GREEN = \033[0;32m
NC = \033[0m

#--------------------------------------------------------------------------

all: $(NAME)

$(PUSHSWAP_OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	mkdir -p $(PUSHSWAP_OBJS_DIR)

$(PUSHSWAP_OBJS_DIR)/%.o: $(PUSHSWAP_DIR)/%.c | $(PUSHSWAP_OBJS_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@printf "$(GREEN)Entering printf directory...$(NC)\n"
	@make --no-print-directory -C $(PRINTF_DIR)
	@printf "$(GREEN)Entering get_next_line directory...$(NC)\n"
	@make --no-print-directory -C $(GNL_DIR)
	@printf "$(GREEN)Entering root directory...$(NC)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(FT_PRINTF) $(GNL)

checker: $(CHECKER)

$(CHECKER_OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	mkdir -p $(CHECKER_OBJS_DIR)

$(CHECKER_OBJS_DIR)/%.o: $(CHECKER_DIR)/%.c | $(CHECKER_OBJS_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CHECKER): $(CHECKER_OBJS)
	@printf "$(GREEN)Entering printf directory...$(NC)\n"
	@make --no-print-directory -C $(PRINTF_DIR)
	@printf "$(GREEN)Entering get_next_line directory...$(NC)\n"
	@make --no-print-directory -C $(GNL_DIR)
	@printf "$(GREEN)Entering root directory...$(NC)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(CHECKER_OBJS) $(FT_PRINTF) $(GNL)

clean:
	@make fclean --no-print-directory -C $(PRINTF_DIR)
	@printf "$(GREEN)Entering get_next_line directory...$(NC)\n"
	@make fclean --no-print-directory -C $(GNL_DIR)
	@printf "$(GREEN)Entering root directory...$(NC)\n"
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all checker clean fclean re
