
NAME   = libftprintf.a

SRC = ./ft_printf.c get_params.c ft_errorrepeatflag.c ft_print.c gettypespec.c ft_handlestr.c ft_handledigits.c alltinyshit.c putfuncs.c printfuncs.c \
		cratches.c getsizes.c ft_putchar.c ft_putstr.c ft_strchr.c ft_strlen.c ft_strcmp.c ft_atoi.c ft_isdigit.c ft_strdup.c ft_putnbr.c
CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = includes/ft_printf.h

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(NAME) $(OBJ)
		 ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean

	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all