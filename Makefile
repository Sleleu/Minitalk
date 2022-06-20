SERVER = server

CLIENT = client

SRC_SERVER = server.c\
			ft_printf/ft_format.c\
			ft_printf/ft_printf.c\
			ft_printf/ft_putchar_fd.c\
			ft_printf/ft_putnbr_fd.c\
			ft_printf/ft_putstr_fd.c\

SRC_CLIENT = client.c\

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ)
		 $(CC) $(CFLAGS) -o $(SERVER) $(SRC_SERVER)

$(CLIENT): $(OBJ)
		   $(CC) $(CFLAGS) -o $(CLIENT) $(SRC_CLIENT)

clean:
		rm -rfv $(OBJ)

fclean: clean
		rm -rfv $(SERVER) $(CLIENT)

re: fclean all

norme:
	@echo "\033[35;36m\n\n === CHECK NORME === \n\n"
	norminette *

.PHONY: all clean fclean re