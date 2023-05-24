NAME = pipex
LIBRARY = libft/libft.a
FLAGS = -Werror -Wextra -Wall
LIBFT = libft/
CC = gcc
X86 = arch -x86_64
SOURCE = srcs/*.c

COMPILE = $(CC) $(FLAGS) $(SOURCE) $(LIBRARY) -o $(NAME)

all:
			$(X86) make -C $(LIBFT)
			$(X86) $(COMPILE)

clean:

fclean:	clean
			make clean -C $(LIBFT)
			rm -rf $(NAME)

re: fclean all
#-g -fsanitize=address