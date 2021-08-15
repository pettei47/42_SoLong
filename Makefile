# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2021/08/14 21:08:14 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
SRCS		=	solong_main.c \
				srcs/sl_checks/sl_check_ber.c \
				srcs/sl_errors/sl_error.c \
				srcs/sl_errors/sl_err_freelong.c \
				srcs/sl_init/sl_init_long.c \
				
OBJS		=	$(SRCS:%.c=%.o)

HEAD		=	./incs/ # your header file
INCS		=	-I./incs
LINK		=	-L./libs
LIBS		=	-lft -lgnl

BONUS_NAME	= # your bonus target file

all: $(NAME)

$(NAME): $(OBJS)
	if [ ! -d libs ]; then mkdir libs; fi
	@make -C libft
	cp libft/libft.a ./libs
	@make -C gnl
	cp gnl/libgnl.a ./libs
	$(CC) -o $(NAME) $(OBJS) $(LINK) $(LIBS) 
%.o: %.c $(HEAD)
	$(CC) $(INCS) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) */*.gch
	rm -rf *.dSYM
fclean: clean
	rm -f $(NAME)
	rm -f libs/*.a
alclean: fclean bfclean
	make fclean -C 42_utils/libft
	make fclean -C 42_utils/gnl

re: fclean all
cl: all clean
reall: alclean all

.PHONY: all clean fclean re cl alclean reall

# if you challenge bonus
bonus:
	make -C bonus
	cp bonus/$(BONUS_NAME) .

bclean:
	make clean -C bonus

bfclean:
	make fclean -C bonus
	rm $(BONUS_NAME)

.PHONY: bonus bclean bfclean
