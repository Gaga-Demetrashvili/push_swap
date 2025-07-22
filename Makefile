NAME = push_swap.a

LIBFT_DIR = Libft
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)
LIBFT_A = $(LIBFT_DIR)/libft.a

SRC = stack_manipulation.c\
	stack_operations.c\
	test.c\
	utils.c\
	validation.c\
	main.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(LIBFT_A):
	$(LIBFT_MAKE)

bonus:
	$(LIBFT_MAKE) bonus

clean:
	rm -f $(OBJ)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -f $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus
