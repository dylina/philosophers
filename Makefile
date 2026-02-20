NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC =	./src/main.c\
		./src/routine.c\
		./src/parse.c\
		./src/utils_lib.c\
		./src/utils_philo.c\
		./src/init.c\
		./src/threads.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re