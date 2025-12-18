# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cclarke <cclarke@student.42prague.com      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 17:58:34 by cclarke           #+#    #+#              #
#    Updated: 2025/12/18 17:43:19 by cclarke          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC	=	cc	
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	ft_printf.h libft/libft.h

SRC	=	ft_printf.c ft_printpercent.c ft_printalnum.c ft_printstr.c ft_printhexaddr.c \
		ft_unsigned_itoa.c ft_printunsigned.c ft_printchar.c

OBJ	=	$(SRC:.c=.o)

LIBFT_P	=	./libft
LIBFT	=	$(LIBF_P)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C $(LIBFT_P)

clean:
	$(MAKE) clean -C $(LIBFT_P)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_P)
	rm -f $(NAME)

re: fclean all
