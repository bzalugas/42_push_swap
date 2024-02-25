#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 19:03:20 by bazaluga          #+#    #+#              #
#    Updated: 2024/02/25 19:13:43 by bazaluga         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	:=	push_swap

SRCDIR	:=	src/

OBJDIR	:=	obj/

SRC		:=	push_swap.c

OBJ		:=	$(SRC:.c=.o)

SRC		:=	$(addprefix($(SRCDIR), $(SRC)))

OBJ		:=	$(addprefix($(OBJDIR), $(OBJ)))

CC		:=	cc

CFLAGS	:=	-Wall -Wextra -Werror

########### COLORS ##########

RED		:=	"\033[31m"
GREEN	:=	"\033[32m"
RESET	:=	"\033[0m"

all:		$(NAME)

.c.o:
			@echo $(GREEN)"Compiling "$<$(RESET)
			@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

bonus:		$(NAME)

clean:
			@echo $(RED)"CLEANING OBJS"
			@rm -f $(OBJ)
			@echo $(RESET)

fclean:		clean
			@echo $(RED)"CLEANING ALL"
			@rm -f $(NAME)
			@rm -f *.out
			@rm -rf *.dSYM
			@echo $(RESET)

re:			fclean
			make -s all

.PHONY:		all clean fclean re
