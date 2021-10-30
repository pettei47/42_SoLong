# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2021/10/30 21:14:24 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
SRCS		=	srcs/solong_main.c \
				srcs/sl_checks/sl_check_ber.c \
				srcs/sl_checks/sl_check_char_exist.c \
				srcs/sl_errors/sl_error.c \
				srcs/sl_init/sl_init_long.c \
				srcs/sl_init/sl_init_map.c \
				srcs/sl_init/sl_init_l_members.c \
				srcs/sl_destroy/sl_free_map.c \
				srcs/sl_destroy/sl_free_long.c \
				srcs/sl_destroy/sl_close_all.c \
				srcs/sl_images/sl_load_texture.c \
				srcs/sl_render/sl_render_frame.c \
				srcs/sl_render/sl_render_player.c \
				srcs/sl_render/sl_draw_img.c \
				srcs/sl_keys/sl_key_hook.c \
				srcs/bonus_enemy/sl_render_enemy.c \
				
OBJS		=	$(SRCS:%.c=%.o)

HEAD		=	./incs/
INCS		=	-I./incs
LINK		=	-L./mlx_mac -L./libft -L./gnl
LIBS		=	-lft -lgnl -lmlx

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a libmlx.dylib gnl/gnl.a
	$(CC) -o $@ $^ $(LINK) $(LIBS)

libft/libft.a:
	make -C libft

gnl/gnl.a:
	make -C gnl

libmlx.dylib:
	make -C mlx_mac 2>/dev/null
	ln -s mlx_mac/libmlx.dylib .

.c.o:
	$(CC) $(INCS) $(CFLAGS) -c $< -o $@

# ifeq ($(shell uname),Darwin)
# else
# mlx:
#	if [ ! -L libmlx.dylib ]; then make -C mlx_linux >/dev/null 2>&1; fi
#	@if [ ! -L libmlx.dylib ]; then ln -s mlx_linux/libmlx.dylib .; fi
# endif

clean:
	@rm -f $(OBJS) */*.gch
	@rm -rf *.dSYM
fclean: clean
	@rm -f $(NAME)
	@rm -rf ./libmlx.dylib

# ifeq ($(shell uname),Darwin)
alclean: fclean
	@make fclean -C libft
	@make fclean -C gnl
	@make clean -C mlx_mac
# else
# alclean: fclean
#	@make fclean -C libft
#	@make fclean -C gnl
#	@make clean -C mlx_linux
# endif

re: alclean all
cl: all clean

.PHONY: all clean fclean re cl alclean

# if you challenge bonus
bonus: all

bclean: clean

bfclean: fclean

.PHONY: bonus bclean bfclean
