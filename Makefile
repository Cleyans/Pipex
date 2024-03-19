NAME := pipex

CC := cc
CFLAGS = -Wall -Wextra -Werror

FT			= include/Libft
LIBFT		= $(FT)/libft.a

SOURCE := src/pipex.c src/utils.c
OBJ 	= $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY:		all bonus clear clean fclean re
