# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mballa <mballa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 23:21:21 by mballa            #+#    #+#              #
#    Updated: 2023/10/03 18:02:16 by mballa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_strdup.c ft_strlcat.c \
		ft_memset.c ft_strchr.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c\
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_mysplit.c

SRCB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c 	ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c  ft_lstmap_bonus.c

OBJECTS = $(SRCS:.c=.o)
OBJECTSB = $(SRCB:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror

#Colors
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
RED 		= 	\e[0;31m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: $(NAME)



$(NAME): $(OBJECTS)
	@printf "$(_SUCCESS) $(YELLOW)- Executable ready.\n$(RESET)"
bonus: $(OBJECTSB) $(OBJECTS)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@ar -rc $(NAME) $@
	
clean: 
	@rm -f $(OBJECTS) $(OBJECTSB)
	@printf "$(RED)- RM *.o .\n$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)- RM *.o .\n$(RESET)"
				
re: fclean all