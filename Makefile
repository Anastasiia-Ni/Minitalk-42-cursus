# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:19:22 by anifanto          #+#    #+#              #
#    Updated: 2021/11/23 18:19:24 by anifanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
NAME_S_B = server_bonus
NAME_C_B = client_bonus

SRCS_S = src/server.c
SRCS_C = src/client.c
SRCS_S_B = src/server_bonus.c
SRCS_C_B = src/client_bonus.c

HEADER = inc/minitalk.h

CFLAGS = -Wall -Wextra -Werror

compile :
	gcc $(CFLAGS) $(SRCS_S) ./libft/*.c $< -o $(NAME_S)
	gcc $(CFLAGS) ${SRCS_C} ./libft/*.c $< -o $(NAME_C)


bonus:
	gcc $(CFLAGS) $(SRCS_S_B) ./libft/*.c $< -o $(NAME_S_B)
	gcc $(CFLAGS) ${SRCS_C_B} ./libft/*.c $< -o $(NAME_C_B)

all:	compile

%.o : %.c
	gcc $(CFLAGS) $< -o $(NAME_S) $(NAME_S_B)

clean:
	rm -rf $(NAME_S) $(NAME_C) $(NAME_S_B) $(NAME_C_B)

fclean: clean

re: fclean all

.PHONY: all clean fclean re