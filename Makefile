#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 19:03:20 by bazaluga          #+#    #+#              #
#    Updated: 2024/03/24 16:47:11 by bazaluga         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		:=	push_swap

NAMEB		:=	checker

NAMEBE		:=	checker_enhanced

SRCDIR		:=	src

OBJDIR		:=	obj

INCDIR		:=	include

LIBFTDIR	:=	libft

LIBFT		:=	libft.a

MAIN	:=	push_swap.c

MAINB	:=	checker.c

SRCBE	:=	checker_enhanced.c checker_enhanced_utils.c

OBJM	:=	$(MAIN:.c=.o)

OBJMB	:=	$(MAINB:.c=.o)

OBJBE	:=	$(SRCBE:.c=.o)

MAIN	:=	$(addprefix $(SRCDIR)/, $(MAIN))

MAINB	:=	$(addprefix $(SRCDIR)/, $(MAINB))

OBJM	:=	$(addprefix $(OBJDIR)/, $(OBJM))

OBJMB	:=	$(addprefix $(OBJDIR)/, $(OBJMB))

OBJBE	:=	$(addprefix $(OBJDIR)/, $(OBJBE))

SRC		:=	op_push.c op_revrotate.c op_rotate.c op_swap.c stack_handling.c \
			stack_handling2.c stacks_handling.c ft_atol_forward.c \
			main_utils.c ft_abs.c lst_cmds.c ft_min_int.c ft_max_int.c sorting.c \
			target_handling.c sorting_utils.c ft_lstremove.c

OBJ		:=	$(SRC:.c=.o)

SRC		:=	$(addprefix $(SRCDIR)/, $(SRC))

OBJ		:=	$(addprefix $(OBJDIR)/, $(OBJ))

CC		:=	cc

CFLAGS		:=	-Wall -Wextra -Werror -MMD -g

########### COLORS ##########

RED		:=	"\033[31m"
GREEN		:=	"\033[32m"
RESET		:=	"\033[0m"

all:			$(NAME)

$(OBJDIR):
			@echo $(GREEN)"Creating obj directory"$(RESET)
			@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:		$(SRCDIR)/%.c | $(OBJDIR)
			@echo $(GREEN)"Compiling "$< "to "$@$(RESET)
			@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

$(LIBFTDIR)/$(LIBFT):
			@echo $(GREEN)"Compiling libft"$(RESET)
			@make -sC $(LIBFTDIR)

$(NAME):		$(LIBFTDIR)/$(LIBFT) $(OBJ) $(OBJM)
			@echo $(GREEN)"MANDATORY PART: Linking objects & creating push_swap"
			$(CC) $(CFLAGS) -I $(INCDIR) $(OBJ) $(OBJM) -o $(NAME) -L$(LIBFTDIR) -lft
			@echo $(RESET)

$(NAMEB):		$(LIBFTDIR)/$(LIBFT) $(OBJ) $(OBJMB)
			@echo $(GREEN)"BONUS PART: Linking objects & creating checker"
			$(CC) $(CFLAGS) -I $(INCDIR) $(OBJ) $(OBJMB) -o $(NAMEB) -L$(LIBFTDIR) -lft
			@echo $(RESET)

$(NAMEBE):		$(LIBFTDIR)/$(LIBFT) $(OBJ) $(OBJBE)
			@echo $(GREEN)"BONUS PART: Linking objects & creating checker"
			$(CC) $(CFLAGS) -I $(INCDIR) $(OBJ) $(OBJBE) -o $(NAMEBE) -L$(LIBFTDIR) -lft
			@echo $(RESET)

libft:
			@make -sC $(LIBFTDIR)

bonus:		$(NAMEB)

bonus2:		$(NAMEBE)

clean:
			@echo $(RED)"CLEANING OBJS"
			@rm -f $(OBJ)
			@rm -f $(OBJ:.o=.d)
			@rm -f $(OBJM)
			@rm -f $(OBJM:.o=.d)
			@rm -f $(OBJMB)
			@rm -f $(OBJMB:.o=.d)
			@rm -f $(OBJBE)
			@rm -f $(OBJBE:.o=.d)
			@echo $(RESET)

fclean:			clean
			@echo $(RED)"CLEANING ALL"
			@rm -f $(NAME)
			@rm -f $(NAMEB)
			@rm -f $(NAMEBE)
			@rm -f *.out
			@rm -rf *.dSYM
			@echo "\nCLEANING LIBFT\n"
			@make -sC $(LIBFTDIR) fclean
			@echo $(RESET)

re:			fclean
			@make all

.PHONY:			all clean fclean re bonus libft

-include		$(OBJ:.o=.d) $(OBJM:.o=.d) $(OBJMB:.o=.d) $(OBJBE:.o=.d)
