# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 12:54:05 by plouvel           #+#    #+#              #
#    Updated: 2022/02/12 19:04:56 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS_DIR	=	objs

SRCS_DIR	=	srcs

LIBFT_DIR	=	libft

SRCS		=	main.c		\
				display.c	\
				game.c		\
				algo.c		\
				parsing.c

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS		=	-I includes -I $(LIBFT_DIR)/includes -g3 -fsanitize=address

CLIBS		=	-L . -lft

CC			=	cc

NAME		=	AlCu

RM			=	rm -rf

LIBFT		=	libft.a

$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(OBJS) $(CFLAGS) $(CLIBS) -o $(NAME) 

all:			$(NAME)

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(LIBFT)
				$(RM) $(NAME)

re:				fclean all

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR) all
				mv $(LIBFT_DIR)/$(LIBFT) .
				$(MAKE) -C $(LIBFT_DIR) fclean

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY:			all clean fclean re
