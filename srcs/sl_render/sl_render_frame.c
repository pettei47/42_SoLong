/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:11:21 by teppei            #+#    #+#             */
/*   Updated: 2021/09/06 23:29:31 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_render_map(t_long *l)
{
	long	x;
	long	y;

	y = -1;
	while (l->m->map[++y])
	{
		x = -1;
		while (l->m->map[y][++x])
		{
			if (l->m->map[y][x] == '1')
				sl_draw_img(l->imgs, l->wall, x * DRAW, y * DRAW);
			else
				sl_draw_img(l->imgs, l->floor, x * DRAW, y * DRAW);
		}
	}
}

void	sl_render_item(t_long *l, t_pict *i, char c)
{
	long	x;
	long	y;

	y = -1;
	while (++y < l->m->map_y)
	{
		x = -1;
		while (++x < l->m->map_x)
		{
			if (l->m->map[y][x] == c)
				sl_draw_img(l->imgs, i, (int)(x * DRAW), (int)(y * DRAW));
		}
	}
}

void	sl_render_player(t_long *l, t_player *p, t_pict *i)
{
	p->mv_x += (p->x - p->mv_x) * 0.5;
	p->mv_y += (p->y - p->mv_y) * 0.5;
	sl_draw_img(i, &(p->img), (int)(p->mv_x * DRAW), (int)(p->mv_y * DRAW));
	if (l->m->map[l->p->y][l->p->x] == 'C')
		l->m->map[l->p->y][l->p->x] = '0';
	if (l->p->y == l->en->y && l->p->x == l->en->x)
		sl_close_all(l);
}

void	sl_check_complete(t_long *l, t_map *m)
{
	long	x;
	long	y;

	y = -1;
	while (++y < m->map_y)
	{
		x = -1;
		while (++x < m->map_x)
		{
			if (m->map[y][x] == 'C')
				return ;
		}
	}
	sl_close_all(l);
}

int	sl_render_frame(t_long *l)
{
	if (l->m->map[l->p->y][l->p->x] == 'E')
		sl_check_complete(l, l->m);
	mlx_do_sync(l->wins->mlx);
	sl_render_map(l);
	sl_render_item(l, l->c, 'C');
	sl_render_item(l, l->e, 'E');
	sl_render_enemy(l, l->en, l->imgs);
	sl_render_player(l, l->p, l->imgs);
	mlx_put_image_to_window(l->wins->mlx, l->wins->win, l->imgs->i, 0, 0);
	return (SUCCESS);
}
