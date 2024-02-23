NAME := pipex

CC := cc

FT			= Libft
LIBFT		= $(FT)/libft.a

SOURCE := pipex.c utils.c
OBJ 	= $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)
	
%.o: %.c
	$(CC) -c $< -o $@

clean:

fclean: clean
		rm -rf $(NAME)
		rm -rf $(OBJ)

re: fclean all

.PHONY:		all bonus clear clean fclean re
