# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scarlucc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 17:46:25 by scarlucc          #+#    #+#              #
#    Updated: 2024/05/17 20:49:07 by scarlucc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SERVER_SRCS = server.c
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_SRCS = client_bonus.c

LIBFT_PATH = Libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
SERVER_NAME = server
CLIENT_NAME = client
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus


all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_SRCS) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) -L$(LIBFT_PATH) -lft

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(LIBFT_PATH) -lft

$(SERVER_BONUS_NAME): $(SERVER_BONUS_SRCS) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_SRCS) -L$(LIBFT_PATH) -lft

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_SRCS) $(LIBFT_ARCHIVE)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_SRCS) -L$(LIBFT_PATH) -lft

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

.PHONY: all clean fclean re bonus
