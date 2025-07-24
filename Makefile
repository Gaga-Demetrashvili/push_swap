NAME = push_swap.a

LIBFT_DIR = Libft
PRINTF_DIR = ft_printf

LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)
PRINTF_MAKE = $(MAKE) -C $(PRINTF_DIR)

LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/ft_printf.a

SRC = push_swap.c\
	stack_operations.c\
	test.c\
	utils.c\
	validation.c\

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT_A) $(PRINTF_A) $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ar -x $(LIBFT_A)
	ar -x $(PRINTF_A)
	ar rc $(NAME) *.o
	rm -f *.o
	rm -f $(LIBFT_DIR)/*.o
	rm -f $(PRINTF_DIR)/*.o

$(LIBFT_A):
	$(LIBFT_MAKE)

$(PRINTF_A):
	$(PRINTF_MAKE)

bonus:
	$(LIBFT_MAKE) bonus
	$(PRINTF_MAKE) bonus

clean:
	rm -f $(OBJ)
	$(LIBFT_MAKE) clean
	$(PRINTF_MAKE) clean

fclean: clean
	rm -f $(NAME)
	$(LIBFT_MAKE) fclean
	$(PRINTF_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus
