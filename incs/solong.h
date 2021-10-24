/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:11:07 by teppei            #+#    #+#             */
/*   Updated: 2021/10/25 00:43:15 by teppei           ###   ########.fr       */
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
# include "../mlx_mac/mlx.h"

# define MLX_ERR	"validateTextureDimensions:1216: failed assertion \
`MTLTextureDescriptor has hight or width greater \
than the maximum allowed size of 16384.'"
# define FAILURE	-1
# define DONE		0
# define SUCCESS	1
# define DRAW		64
# define BLACKCOLOR	0xFF000000
# define ESC		53
# define SPACE		49
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
# define BUF_SIZE	1024
# define PLAYER		"./textures/player_01.xpm"
# define ENEMY		"./textures/enemy_01.xpm"
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
	t_player		*en;
	bool			enemy;
	long			enemy_mv;
	t_pict			*c;
	t_pict			*e;
	t_wins			*wins;
	t_pict			*imgs;
	t_pict			*wall;
	t_pict			*floor;
	t_map			*m;
	int				moves;
	unsigned int	frame;
}					t_long;

/* check input file */
void		sl_check_ber(char **av, t_map *m);
void		sl_check_char_exist(t_map *m);
/* error handling */
void		sl_error(char *msg, void *p, int f);
/* init structs */
t_long		*sl_init_long(t_map *m);
void		sl_init_map(t_map *m);
void		sl_set_map(char *file, t_map *m);
t_player	*sl_init_player(t_map *m);
t_player	*sl_init_enemy(void);
t_pict		*sl_init_pict(void);
t_wins		*sl_init_wins(void);
/* destructors */
void		sl_free_long(t_long *l);
void		sl_free_map(t_map *m);
void		sl_free_img(t_pict *i);
void		sl_free_wins(t_wins *w);
int			sl_close_all(t_long *l);
/* image handling*/
t_pict		sl_load_texture(t_long *l, char *path);
t_pict		*sl_set_texture_img(t_long *l, char *path);
/* render frame*/
int			sl_render_frame(t_long *l);
void		sl_render_player(t_long *l, t_player *p, t_pict *i);
void		sl_draw_img(t_pict *img, t_pict *img2, int x, int y);
int			sl_key_hook(int key, t_long *l);
void		sl_render_enemy(t_long *l, t_player *en, t_pict *img);

#endif
