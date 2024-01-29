SRC =  philo.c philo_utils.c init_philo.c
NAME = philo
OBJ= $(SRC_FILE:.c=.o)
CFLAGS = #-Wall -Werror -Wextra
HEADER = pipex.h
cc = gcc
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ) 
	gcc $(CFLAGS) $(SRC) -o $(NAME)

%.o:%.c $(HEADER)
	$(cc) $(CFLAGS) -c $< -o $@
clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all