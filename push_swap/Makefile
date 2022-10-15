NAME = push_swap
BONUS_NAME = checker

LIBFTDIR = ./lib/libft
PRINTFDIR = ./lib/printf
GNLDIR = ./lib/gnl
DIR = ./mandatory
BONUS_DIR = ./bonus

FT_PRINTF = ./lib/printf/libftprintf.a -L$(PRINTFDIR) -lftprintf
GNL = ./lib/gnl/get_next_line.a

FILES = main\
		make_stacks\
		make_stacks_ii\
		atoi\
		push\
		swap\
		lst_funcs\
		sort
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

CFLAGS = -Wall -Wextra -Werror -g3 -I ./includes

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
	make clean -C $(PRINTFDIR)
	make clean -C $(GNLDIR)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(PRINTFDIR)
	make fclean -C $(GNLDIR)
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus