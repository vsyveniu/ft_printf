NAME   = libftprintf.a

NAME2 = test

SRC	 = 	ft_putchar.c ft_putstr.c ft_strchr.c ft_strlen.c ft_strcmp.c ft_atoi.c ft_isdigit.c ft_strdup.c ft_putnbr.c

SRCTEST = ./ft_printf.c get_params.c ft_errorrepeatflag.c ft_print.c gettypespec.c ft_handlestr.c ft_handledigits.c alltinyshit.c putfuncs.c printfuncs.c \
			cratches.c getsizes.c


CC = gcc

FLAGS = -Wall -Wextra

HEADER = ft_printf.h

OBJ = $(SRC:.c=.o)

OBJ2 = ./ft_printf.o

all: $(NAME2) 

$(NAME): $(NAME) $(OBJ)
		 ar rcs $(NAME) $(OBJ)

$(NAME2): $(NAME)
	 $(CC) $(FLAGS) $(SRCTEST) -L. libftprintf.a -o $(NAME2)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean: clean
	
	rm -f $(NAME)
	rm -f $(NAME2)

re: fclean all
