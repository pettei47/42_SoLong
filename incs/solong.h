/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:11:07 by teppei            #+#    #+#             */
/*   Updated: 2021/08/16 01:00:05 by teppei           ###   ########.fr       */
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
# define MAP_ELEM	"PCE"
# define MAP_CHAR	"10PCE"
# define BUF_SIZE	3

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
/* error handling */
void	sl_error(char *msg, int f);
void	sl_err_freelong(char *msg, t_long *l);
/* init structs */
void	sl_init_long(t_long *l);
void	sl_set_map(char *file, t_long *l);

#endif
