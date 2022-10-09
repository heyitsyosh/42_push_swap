NAME = push_swap
BONUS_NAME = checker

LIBFTDIR = ./lib/libft
PRINTFDIR = ./lib/printf
GNLDIR = ./lib/gnl
DIR = ./mandatory
BONUS_DIR = ./bonus

FT_PRINTF = ./lib/printf/libftprintf.a -L$(PRINTFDIR) -lftprintf
GNL = ./lib/gnl/get_next_line.a 

FILES = 
BONUS_FILES = main\
			get_inputs\
			atoi\
			push_swap\
			rotate\
			rev_rotate

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = $(foreach bonus_src,$(BONUS_FILES),./bonus/$(bonus_src)_bonus.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I ./includes

/* -------------------------------------------------------------------------- */

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)
	make -C $(GNLDIR)

bonus: all

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