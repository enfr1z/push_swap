# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 12:46:11 by pdiedra           #+#    #+#              #
#    Updated: 2019/08/31 16:41:08 by pdiedra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		= libft.a

INC_PATH	= ./includes/
SRC_PATH 	= ./src/
OBJ_DIR		= ./obj/

HEADER_NAME	= libft.h get_next_line.h

SRC_NAME	= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putchar.c ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr.c\
ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c \
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_swap.c ft_bubble_sort.c ft_is_prime.c ft_max.c ft_count_words.c ft_realloc.c \
ft_atoi_base.c ft_abs.c ft_pow.c ft_skipspace.c ft_isspace.c get_next_line.c \
ft_free_array.c

OBJ_NAME	= $(SRC_NAME:.c=.o)


SRC			= $(addprefix $(SRC_PATH), $(SRC_NAME))
HEADER		= $(addprefix $(INC_PATH), $(HEADER_NAME))
OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_NAME))

RED			=\033[0;31m
GREEN		=\033[0;32m
BLUE		=\033[0;34m
YELLOW		=\033[0;33m

FLAGS 		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)\t\t\tLibft compile compete"

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_PATH)%.c $(HEADER)
	@echo "$(YELLOW)gcc -c -I $(INC_PATH) $(FLAGS) $< -o $@"
	@gcc -c -I $(INC_PATH) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "$(RED)Libft object file removed"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(RED)Libft.a removed"

re: fclean all
