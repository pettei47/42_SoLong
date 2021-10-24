/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 00:32:27 by teppei            #+#    #+#             */
/*   Updated: 2021/10/25 00:39:03 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_draw_player(t_player *p, t_pict *img)
{
	sl_draw_img(img, &(p->img), (int)(p->mv_x * DRAW), (int)(p->mv_y * DRAW));
}

void	sl_render_player(t_long *l, t_player *p, t_pict *i)
{
	p->mv_x += (p->x - p->mv_x) * 0.5;
	p->mv_y += (p->y - p->mv_y) * 0.5;
	sl_draw_player(p, i);
	if (l->m->map[l->p->y][l->p->x] == 'C')
		l->m->map[l->p->y][l->p->x] = '0';
	if (l->p->y == l->en->y && l->p->x == l->en->x)
		sl_close_all(l);
}
