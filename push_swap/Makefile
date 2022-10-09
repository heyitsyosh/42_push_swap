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

SRCS = $(addsuffix .c, $(SRCS_))
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I ./includes

/* -------------------------------------------------------------------------- */

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTFDIR)

bonus: all

clean:
	make clean -C $(PRINTFDIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(PRINTFDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus