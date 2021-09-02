/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:11:07 by teppei            #+#    #+#             */
/*   Updated: 2021/09/03 03:07:08 by teppei           ###   ########.fr       */
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
# include "./mlx.h"

# define FAILURE	-1
# define DONE		0
# define SUCCESS	1
# define DRAW		64
# define BLACKCOLOR	0xFF000000
# define ESC		53
# define W			13
# define S			1
# define D			2
# define A			0
# define P			35
# define RIGHT		124
# define LEFT		123
# define J			38
# define K			40
# define L			37
# define MAP_ELEM	"CEP"
# define MAP_CHAR	"10CEP"
# define BUF_SIZE	200
# define PLAYER		"./textures/player_02.xpm"
# define WALL		"./textures/wall_01.xpm"
# define FLOOR		"./textures/sand.xpm"
# define EXIT_PICT	"./textures/door_01.xpm"
# define COLLECT	"./textures/plant_01.xpm"

typedef struct s_pict
{
	void		*i;
	char		*addr;
	int			w;
	int			h;
	int			bpp;
	int			line;
	int			endian;
}				t_pict;

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
	t_pict	img;
	int		x;
	int		y;
	float	mv_x;
	float	mv_y;
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
	t_pict		img;
}				t_collects;

typedef struct s_exit
{
	int				pos_x;
	int				pos_y;
	bool			is_touched;
	struct s_exit	*next;
}				t_exit;

typedef struct s_exits
{
	t_pict	img;
	t_exit	*first;
}			t_exits;

typedef struct s_v
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	an;
}				t_v;

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
	t_pict			*imgs;
	t_pict			*wall;
	t_pict			*floor;
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
t_player	*sl_init_player(t_map *m);
t_collects	*sl_init_collects(void);
t_exits		*sl_init_exits(void);
t_pict		*sl_init_pict(void);
t_wins		*sl_init_wins(void);
/* destructors */
void		sl_free_long(t_long *l);
void		sl_free_map(t_map *m);
void		sl_free_player(t_player *p);
void		sl_free_collects(t_collects *c);
void		sl_free_exits(t_exits *e);
void		sl_free_img(t_pict *i);
void		sl_free_wins(t_wins *w);
int			sl_close_all(t_long *l);
/* image handling*/
t_pict		sl_load_texture(t_long *l, char *path);
t_pict		*sl_set_texture_img(t_long *l, char *path);
/* render frame*/
int			sl_render_frame(t_long *l);
void		sl_draw_img(t_pict *img, t_pict *img2, int x, int y);


#endif
