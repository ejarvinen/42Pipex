# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 06:17:38 by emansoor          #+#    #+#              #
#    Updated: 2024/05/05 10:48:38 by emansoor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = main.c \
		pipex.c \
		utils.c \
		struct_utils.c \
		input_validation.c \

OFILES = $(CFILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OFILES)
	make -C ./libft
	make bonus -C ./libft
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)
	
clean:
	make -C ./libft clean
	rm -f $(OFILES)
	
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re        