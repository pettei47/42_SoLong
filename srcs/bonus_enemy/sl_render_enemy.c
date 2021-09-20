/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:55:16 by teppei            #+#    #+#             */
/*   Updated: 2021/09/20 18:45:22 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_set_enemy_start(t_map *m, t_player *en, int rand)
{
	long	y;
	long	x;
	long	cnt;

	cnt = 0;
	y = -1;
	while (++y < m->map_y)
	{
		x = -1;
		while (++x < m->map_x)
		{
			if (m->map[y][x] == '0')
				cnt++;
			if (cnt == rand)
			{
				en->x = x;
				en->y = y;
				return ;
			}
		}
	}
	ft_putendl_fd("map has no space for enemy", 1);
}

void	sl_move_enemy(t_long *l, int mv)
{
	long	x;
	long	y;

	x = l->en->x;
	y = l->en->y;
	if (l->m->map[(int)(y - 1)][(int)x] != '1' && mv == 0)
		l->en->y -= 1;
	else if (l->m->map[(int)y][(int)(x - 1)] != '1' && mv == 1)
		l->en->x -= 1;
	else if (l->m->map[(int)(y + 1)][(int)x] != '1' && mv == 2)
		l->en->y += 1;
	else if (l->m->map[(int)y][(int)(x + 1)] != '1' && mv == 3)
		l->en->x += 1;
	else
		return ;
}

void	sl_render_enemy(t_long *l, t_player *en, t_pict *img)
{
	static long	mv;
	long		map_size;

	mv++;
	mv = (l->enemy_mv * l->enemy_mv + mv) % 101;
	l->enemy_mv += mv;
	map_size = (l->m->map_y - 2) * (l->m->map_x - 2);
	if (l->enemy == true)
	{
		sl_set_enemy_start(l->m, l->en, l->enemy_mv % map_size);
		l->enemy = false;
	}
	else if (l->en->x > 0)
		sl_move_enemy(l, mv);
	else
		return ;
	en->mv_x += (en->x - en->mv_x) * 0.5;
	en->mv_y += (en->y - en->mv_y) * 0.5;
	sl_draw_img(img, &(en->img), (int)(en->mv_x * DRAW), (int)(en->mv_y * DRAW));
}
