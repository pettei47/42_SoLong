/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:18:44 by teppei            #+#    #+#             */
/*   Updated: 2021/09/03 03:11:45 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_loop(t_long *l)
{
	mlx_loop_hook(l->wins->mlx, sl_render_frame, l);
	//mlx_hook(l->wins->win, 2, 1L << 0, key_hook, mem);
	//mlx_hook(l->wins->win, 33, 1L << 5, sl_close_all, l);
	mlx_loop(l->wins->mlx);
}

void	sl_init_mlx(t_long *l, void *mlx, t_map *m)
{
	int	x;
	int	y;
	int	sc_x;
	int	sc_y;

	x = m->map_x * 64;
	y = m->map_y * 64;
	mlx_get_screen_size(l->wins->mlx, &sc_x, &sc_y);
	l->wins->win = mlx_new_window(mlx, x, y, "SoLong");
	l->imgs->i = mlx_new_image(mlx, x, y);
	l->imgs->addr = mlx_get_data_addr(l->imgs->i, \
					&l->imgs->bpp, &l->imgs->line, &l->imgs->endian);
}

void	sl_set_textures(t_long *l)
{
	l->p->img = sl_load_texture(l, PLAYER);
	l->wall = sl_set_texture_img(l, WALL);
	l->floor = sl_set_texture_img(l, FLOOR);
	l->e->img = sl_load_texture(l, EXIT_PICT);
	l->c->img = sl_load_texture(l, COLLECT);
}

int	main(int ac, char **av)
{
	t_long	*l;
	t_map	map;

	if (ac != 2)
		sl_error("must be 1 argments.", NULL, 3);
	sl_init_map(&map);
	sl_check_ber(ac, av, &map);
	for (int i = 0; i < map.map_y; i++)
		printf("[%d]%s\n", i, map.map[i]);
	l = sl_init_long(&map);
	l->wins->mlx = mlx_init();
	sl_init_mlx(l, l->wins->mlx, l->m);
	sl_set_textures(l);
	sl_loop(l);
	sl_free_long(l);
	return (0);
}
