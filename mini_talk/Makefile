# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschweit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 10:51:30 by bschweit          #+#    #+#              #
#    Updated: 2022/07/05 10:24:56 by bschweit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_SERV = src/server.c
SRC_CLIENT = src/client.c

FONT_COLOR_GREEN = '\033[0;32m'
FONT_COLOR_RED = '\033[0;31m'
FONT_COLOR_DEFAULT = '\033[0m'

OBJS_SERV = $(SRC_SERV:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)

NAME_SERV = server
NAME_CLIENT = client

MOVE = mv $(NAME_SERV) Executable && mv $(NAME_CLIENT) Executable
FLAGS = -Wall -Werror -Wextra
RM = rm -f
EXEC = mkdir Executable
LIBFT = libft.a libftprintf.a

.SILENT : $(OBJS_SERV) $(OBJS_CLIENT)

all: $(NAME_SERV) $(NAME_CLIENT)

$(NAME_SERV): $(OBJS_SERV)
	@gcc $(FLAGS) $(OBJS_SERV) $(LIBFT) -o $(NAME_SERV) && $(EXEC)
	@echo $(FONT_COLOR_GREEN)[SERVER EXECUTABLE CREATED] $(FONT_COLOR_DEFAULT)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@gcc $(FLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT) && $(MOVE)
	@echo $(FONT_COLOR_GREEN)[CLIENT EXECUTABLE CREATED] $(FONT_COLOR_DEFAULT)

clean:
	@$(RM) $(OBJS_SERV) && $(RM) $(OBJS_CLIENT)
	@echo $(FONT_COLOR_RED)[OBJECT DELETED] $(FONT_COLOR_DEFAULT)

fclean :clean
	@$(RM) $(NAME_SERV) && $(RM) $(NAME_CLIENT)
	@rm -rf Executable
	@echo $(FONT_COLOR_RED)[EXECUTABLE DELETED] $(FONT_COLOR_DEFAULT)
re: fclean all

.PHONY: all clean fclean re
