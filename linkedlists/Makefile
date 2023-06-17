NAME = list

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = src/printlist.c src/insertnode.c src/deletenode.c \
	  src/operations.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all