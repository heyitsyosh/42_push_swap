NAME = push_swap
BONUS_NAME = checker

LIBFTDIR = ./lib/libft
PRINTFDIR = ./lib/printf
GNLDIR = ./lib/gnl
DIR = ./mandatory
BONUS_DIR = ./bonus
OBJS_DIR = ./objs

FT_PRINTF = ./lib/printf/libftprintf.a -L$(PRINTFDIR) -lftprintf
GNL = ./lib/gnl/get_next_line.a

FILES = main\
		atoi\
		make_stacks\
		make_stacks_ii\
		actions/push\
		actions/swap\
		actions/rotate\
		actions/rev_rotate\
		lst_utils\
		commands\
		reduce_commands\
		sort_few\
		sort_many\
		divide\
		divide_utils\
		combine\
		combine_utils
BONUS_FILES = main\
			get_inputs\
			atoi\
			push_swap\
			rotations\
			exit

SRCS = $(foreach src,$(FILES),./mandatory/$(src).c)
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = $(foreach bonus_src,$(BONUS_FILES),./bonus/$(bonus_src)_bonus.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I ./includes
CC = gcc

#--------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	make -C $(GNLDIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(FT_PRINTF) $(GNL)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	make -C $(PRINTFDIR)
	make -C $(GNLDIR)
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS) $(FT_PRINTF) $(GNL)

clean:
	make fclean -C $(PRINTFDIR)
	make fclean -C $(GNLDIR)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus