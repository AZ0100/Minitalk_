# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: az0100 <az0100@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 12:31:18 by az0100            #+#    #+#              #
#    Updated: 2023/08/16 12:58:33 by az0100           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = cc -Wall -Wextra -Werror
RM = rm -rf

CFILES_SERVER = server.c utils.c
OBJ_SERVER = $(CFILES_SERVER:%.c=%.o)

CFILES_CLIENT = client.c utils.c
OBJ_CLIENT = $(CFILES_CLIENT:%.c=%.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) utils.c client.c -o $(CLIENT)
	
$(SERVER): $(OBJ_CLIENT)
	$(CC) utils.c server.c -o $(SERVER)
	
%.o: %.c
	$(CC) -c $< -o $@
	
clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	
fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all	
	