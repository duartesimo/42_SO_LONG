CFILES = ft_printf.c helper_functions.c
OBJECTS = ${CFILES:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJECTS)

re: fclean all

.PHONY: all fclean clean re