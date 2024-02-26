#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 19:03:20 by bazaluga          #+#    #+#              #
#    Updated: 2024/02/26 13:10:10 by bazaluga         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		:=	push_swap

SRCDIR		:=	src

OBJDIR		:=	obj

INCDIR		:=	include

LIBFTDIR	:=	libft

LIBFT		:=	libft.a

SRC			:=	push_swap.c

OBJ			:=	$(SRC:.c=.o)

SRC			:=	$(addprefix $(SRCDIR)/, $(SRC))

OBJ			:=	$(addprefix $(OBJDIR)/, $(OBJ))

CC			:=	cc

CFLAGS		:=	-Wall -Wextra -Werror -MMD

########### COLORS ##########

RED			:=	"\033[31m"
GREEN		:=	"\033[32m"
RESET		:=	"\033[0m"

all:				$(NAME)

$(OBJDIR):
					mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:		$(SRCDIR)/%.c | $(OBJDIR)
					@echo $(GREEN)"Compiling "$<$(RESET)
					@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

$(LIBFTDIR)/$(LIBFT):
						@echo $(GREEN)"Compiling libft"$(RESET)
						@make -C $(LIBFTDIR)

$(OBJDIR)/$(LIBFT):	$(LIBFTDIR)/$(LIBFT) | $(OBJDIR)
					@echo $(GREEN)"Copying libft"
					cp $(LIBFTDIR)/$(LIBFT) $(OBJDIR)/$(LIBFT)
					@echo $(RESET)

$(NAME):			$(OBJDIR)/$(LIBFT) $(OBJ)
					$(CC) $(CFLAGS) -I $(INCDIR) $(OBJ) -o $(NAME)

bonus:				$(NAME)

clean:
					@echo $(RED)"CLEANING OBJS"
					@rm -f $(OBJ)
					@echo $(RESET)

fclean:				clean
					@echo $(RED)"CLEANING ALL"
					@rm -f $(NAME)
					@rm -f $(OBJDIR)/$(LIBFT)
					@rm -f *.out
					@rm -rf *.dSYM
					@make -sC $(LIBFTDIR) fclean
					@echo $(RESET)

re:					fclean
					make -s all

.PHONY:				all clean fclean re

-include			$(OBJ:.o=.d)