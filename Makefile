# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teppei <teppei@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 12:46:40 by teppei            #+#    #+#              #
#    Updated: 2021/09/20 18:38:02 by teppei           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
SRCS		=	solong_main.c \
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
				srcs/sl_render/sl_draw_img.c \
				srcs/sl_keys/sl_key_hook.c \
				srcs/bonus_enemy/sl_render_enemy.c \
				
OBJS		=	$(SRCS:%.c=%.o)

HEAD		=	./incs/
INCS		=	-I./incs
LINK		=	-L./libs
LIBS		=	-lft -lgnl -lmlx

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LINK) $(LIBS)

# ifeq ($(shell uname),Darwin)
# else
# mlx:
#	@make -C mlx_linux
#	@cp mlx_linux/libmlx.dylib ./libs
#	@cp mlx_linux/libmlx.dylib ./
#	@cp mlx_linux/mlx.h ./incs
# endif

mlx:
	@if [ ! -d libs ]; then mkdir libs; fi
	@make -C mlx_mac >dev/null 2>&1
	@if [ ! -e libs/libmlx.dylib ]; then cp mlx_mac/libmlx.dylib libs; fi
	@if [ ! -e libmlx.dylib ]; then cp mlx_mac/libmlx.dylib .; fi
	@if [ ! -e incs/mlx.h ]; then cp mlx_mac/mlx.h incs; fi

ftgnl:
	@if [ ! -d libs ]; then mkdir libs; fi
	@make -C libft
	@if [ ! -e libs/libft.a ]; then cp libft/libft.a libs; else echo OK; fi
	@make -C gnl
	@if [ ! -e libs/libgnl.a ]; then cp gnl/libgnl.a libs; else echo OK; fi

.c.o:
	@if [ ! -d libs ]; then mkdir libs; fi
# make mlx
	@make -C mlx_mac >/dev/null 2>&1
	@if [ ! -e libs/libmlx.dylib ]; then cp mlx_mac/libmlx.dylib libs; fi
	@if [ ! -e libmlx.dylib ]; then cp mlx_mac/libmlx.dylib .; fi
	@if [ ! -e incs/mlx.h ]; then cp mlx_mac/mlx.h incs; fi
# make libft & gnl
	@make -C libft >/dev/null 2>&1
	@if [ ! -e libs/libft.a ]; then cp libft/libft.a libs; fi
	@make -C gnl >/dev/null 2>&1
	@if [ ! -e libs/libgnl.a ]; then cp gnl/libgnl.a libs; fi
# compile c->o
	$(CC) $(INCS) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) */*.gch
	@rm -rf *.dSYM
fclean: clean
	@rm -f $(NAME)
	@rm -f libs/*.a
	@rm -rf libs/libmlx.dylib
	@rm -rf ./libmlx.dylib
	@rm -f incs/mlx.h

ifeq ($(shell uname),Darwin)
alclean: fclean
	@make fclean -C libft
	@make fclean -C gnl
	@make clean -C mlx_mac
else
alclean: fclean
	@make fclean -C libft
	@make fclean -C gnl
	@make clean -C mlx_linux
endif

re: fclean all
cl: all clean
reall: alclean all

.PHONY: all clean fclean re cl alclean reall

# if you challenge bonus
bonus: all

bclean: clean

bfclean: fclean

.PHONY: bonus bclean bfclean
