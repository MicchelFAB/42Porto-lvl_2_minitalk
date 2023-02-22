CC = cc
FLAGS = -Wall -Wextra -Werror
AR			= ar rc
RM			= rm -rf

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SERVER = server
SERVER_B = server_b
CLIENT = client
CLIENT_B = client_b
SRC-S = server.c
SRC-C = client.c
SRC_B-S = server_bonus.c
SRC_B-C = client_bonus.c

OBJ-S = $(SRC-S:.c=.o)
OBJ-C = $(SRC-C:.c=.o)
OBJ_B-S = $(SRC_B-S:.c=.o)
OBJ_B-C = $(SRC_B-C:.c=.o)

NAME = $(SERVER) $(CLIENT)
N_BONUS = $(SERVER_B) $(CLIENT_B)
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)			
$(SERVER): $(OBJ-S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ-S) $(LIBFT) -o server
$(CLIENT): $(OBJ-C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ-C) $(LIBFT) -o client
$(SERVER_B): $(OBJ_B-S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_B-S) $(LIBFT) -o server_b
$(CLIENT_B): $(OBJ_B-C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_B-C) $(LIBFT) -o client_b

clean:
	@make clean -C ./libft
	$(RM) $(OBJ-S) $(OBJ-C) $(OBJ_B-S) $(OBJ_B-C)

fclean: clean
	@make fclean -C ./libft
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER_B) $(CLIENT_B)

re:			fclean all

bonus: $(N_BONUS)

.PHONY:		all clean fclean re libft bonus
