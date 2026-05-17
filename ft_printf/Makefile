# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gopiment <gopiment@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/07 15:54:13 by gopiment          #+#    #+#              #
#    Updated: 2026/05/17 05:28:56 by gopiment         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
AR          = ar rcs
RM          = rm -f

SRCS        = ft_printf.c utils.c print_disorder.c

SRC_OBJS    = $(SRCS:.c=.o)

LIBFT_DIR   = ../libft
LIBFT       = $(LIBFT_DIR)/libft.a

.c.o:
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o ${<:.c=.o}

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SRC_OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar q $(NAME) $(SRC_OBJS)
	ranlib $(NAME)
	@echo "FT_PRINTF - Done!"

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(SRC_OBJS)
	@echo "CLEAN - Done!"

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	@echo "FCLEAN - Done!"

re: fclean all

# bonus: all

.PHONY: all clean fclean re bonus