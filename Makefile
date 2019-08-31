# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/30 16:26:06 by pdiedra           #+#    #+#              #
#    Updated: 2019/08/31 17:06:43 by pdiedra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all relib clean fclean re

NAME_PS			=	push_swap
NAME_CH			=	checker
NAME_LB			=	libft.a

SRC_PATH		=	./src/
OBJ_PATH		=	./obj/
LIB_PATH		=	./libft/
INC_PATH		=	./includes/

SRC_NAME_PS		=	commands.c ft_push_swap.c ft_stack_pop.c sort_utils.c utils.c \
					commands_utils.c ft_sort.c ft_stack_push.c stack.c valid.c
SRC_NAME_CH		=	commands.c ft_checker.c ft_stack_pop.c sort_utils.c utils.c \
					commands_utils.c ft_sort.c ft_stack_push.c stack.c valid.c
OBJ_NAME_PS		=	$(SRC_NAME_PS:.c=.o)
OBJ_NAME_CH		=	$(SRC_NAME_CH:.c=.o)
INC_NAME		=	push_swap.h

INC				=	$(addprefix $(INC_PATH), $(INC_NAME))
LIB				=	$(addprefix $(LIB_PATH), $(NAME_LB))
SRC_PS			=	$(addprefix $(SRC_PATH), $(SRC_NAME_PS))
SRC_CH			=	$(addprefix $(SRC_PATH), $(SRC_NAME_CH))
OBJ_PS			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME_PS))
OBJ_CH			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME_CH))

FLAG			=	-Wall -Wextra -Werror
CC				=	gcc

RED				=	\033[0;31m
GREEN			=	\033[0;32m
BLUE			=	\033[0;34m
YELLOW			=	\033[0;33m

all: $(NAME_PS) $(NAME_CH) 

$(NAME_PS): $(OBJ_PATH) $(LIB) $(OBJ_PS)
	@$(CC) $(OBJ_PS) -L $(LIB_PATH) -lft -o $(NAME_PS) $(FLAG)

$(NAME_CH): $(OBJ_CH)
	@$(CC) $(OBJ_CH) -L $(LIB_PATH) -lft -o $(NAME_CH) $(FLAG)
	
$(OBJ_PATH):
	@mkdir -p obj

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@$(CC) -c -I $(INC_PATH) -I $(LIB_PATH)$(INC_PATH) $(FLAG) $< -o $@

$(LIB):
	@make -sC $(LIB_PATH)

relib:
	@make re -sC $(LIB_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -sC $(LIB_PATH)

fclean: clean
	@rm -f $(NAME_CH)
	@rm -f $(NAME_PS)
	@make fclean -sC $(LIB_PATH)

re: fclean all