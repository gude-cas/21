NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = functions/ft_atoi.c functions/ft_isascii.c functions/ft_isdigit.c functions/ft_isprint.c \
		functions/ft_itoa.c functions/ft_split.c functions/ft_strchr.c functions/ft_strjoin.c functions/ft_strlen.c \

PRINTF = printf/ft_printf.c printf/ft_putladd.c printf/ft_putlchar.c \
		 printf/ft_putlhex.c printf/ft_putlstr.c printf/ft_putlnbr.c \

GNL = get_next_line/get_next_line.c \

OBJ = $(LIBFT:.c=.o) $(PRINTF:.c=.o) $(GNL:.c=.o)

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