/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:11:07 by teppei            #+#    #+#             */
/*   Updated: 2021/08/16 22:26:02 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# define FAILURE	1
# define SUCCESS	0
# define MAP_ELEM	"CEP"
# define MAP_CHAR	"10CEP"
# define BUF_SIZE	200

typedef struct s_img
{
	void		*img;
	char		*addr;
	long		w;
	long		h;
	long		bpp;
	long		line;
	long		endian;
}				t_img;

typedef struct s_long
{
	char		**map;
	long		map_x;
	long		map_y;
}				t_long;

/* check input file */
void	sl_check_ber(int ac, char **av, t_long *l);
void	sl_check_char_exist(t_long *l);
/* error handling */
void	sl_error(char *msg, t_long *l, int f);
/* init structs */
void	sl_init_long(t_long *l);
void	sl_set_map(char *file, t_long *l);
/* destructors */
void	sl_free_long(t_long *l);

#endif
