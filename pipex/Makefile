NAME = pipex

CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADER = pipex.h

SRC = pipex.c utils.c ft_split.c ft_strlen.c ft_strncmp.c

OBJ = $(SRC:c=o)

SRCB = utils.c

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ) $(OBJB)
	@echo "\033[0m"

fclean:
	@rm -f $(OBJ) $(OBJB)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
