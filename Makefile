CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx

all: 
	$(CC) *.c $(FLAGS)

fclean:
	  rm -rf a.out
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.PHONY: re
