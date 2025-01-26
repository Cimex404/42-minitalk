# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 08:32:17 by jgraf             #+#    #+#              #
#    Updated: 2024/11/14 08:32:20 by jgraf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		COMPLIER RULES AND NAMES		#
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SERVER = server
CLIENT = client
SERVER_CFILES = src/server.c
SERVER_OFILES = $(SERVER_CFILES:.c=.o)
CLIENT_CFILES = src/client.c src/ft_atoi.c
CLIENT_OFILES = $(CLIENT_CFILES:.c=.o)


#		CREATE EXECUTABLES		#
all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OFILES)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OFILES)

$(CLIENT): $(CLIENT_OFILES)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


#		CLEAN UP		#
clean:
	rm -f $(SERVER_OFILES) $(CLIENT_OFILES)

fclean: clean
	rm -f $(SERVER) $(CLIENT)


#		RECOMPILE		#
re: fclean all

.PHONY: all clean fclean re
