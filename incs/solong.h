/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:11:07 by teppei            #+#    #+#             */
/*   Updated: 2021/08/28 13:59:50 by teppei           ###   ########.fr       */
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
	void		*i;
	char		*addr;
	long		w;
	long		h;
	long		bpp;
	long		line;
	long		endian;
}				t_img;

typedef struct s_map
{
	char		**map;
	long		map_x;
	long		map_y;
}				t_map;

typedef struct s_wins {
	void	*mlx;
	void	*win;
}				t_wins;

typedef struct s_player
{
	t_img	img;
	int		x;
	int		y;
	float	smooth_x;
	float	smooth_y;
	bool	is_found;
}				t_player;

typedef struct s_collect
{
	int					pos_x;
	int					pos_y;
	bool				is_touched;
	struct s_collect	*next;
}				t_collect;

typedef struct s_collects
{
	t_collect	*first;
	bool		is_empty;
	t_img		img;
}				t_collects;

/* Liste chainee pour les exits */
typedef struct s_exit
{
	int				pos_x;
	int				pos_y;
	bool			is_touched;
	struct s_exit	*next;
}				t_exit;

typedef struct s_exits
{
	t_img	img;
	t_exit	*first;
	bool	is_empty;
}			t_exits;

typedef struct s_v
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	an;
}				t_v;

/* Variables necessaires pour le rapport de proportionnalite */
typedef struct s_draw
{
	int		x;
	int		y;
	float	r_x;
	float	r_y;
	int		color;
	int		pos_x;
	int		pos_y;
	int		p_data_x;
	int		p_data_y;
}				t_draw;

typedef struct s_long
{
	t_player		*p;
	t_collects		*c;
	t_exits			*e;
	t_wins			*wins;
	t_img			*imgs;
	t_img			*floor;
	t_img			*bottom;
	t_map			*m;
	int				moves;
	unsigned int	frame;
}					t_long;

/* check input file */
void		sl_check_ber(int ac, char **av, t_map *m);
void		sl_check_char_exist(t_map *m);
/* error handling */
void		sl_error(char *msg, void *p, int f);
/* init structs */
t_long		*sl_init_long(t_map *m);
void		sl_init_map(t_map *m);
void		sl_set_map(char *file, t_map *m);
t_player	*sl_init_player(void);
t_collects	*sl_init_collects(void);
t_exits		*sl_init_exits(void);
t_img		*sl_init_img(void);
t_wins		*sl_init_wins(void);
/* destructors */
void		sl_free_long(t_long *l);
void		sl_free_map(t_map *m);
void		sl_free_player(t_player *p);
void		sl_free_collects(t_collects *c);
void		sl_free_exits(t_exits *e);
void		sl_free_img(t_img *i);
void		sl_free_wins(t_wins *w);

#endif
