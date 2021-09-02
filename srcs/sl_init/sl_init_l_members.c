/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_l_members.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 09:37:14 by teppei            #+#    #+#             */
/*   Updated: 2021/09/03 00:11:18 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_player	*sl_init_player(t_map *m)
{
	t_player	*p;
	long		x;
	long		y;

	p = (t_player *)malloc(sizeof(t_player));
	if (!p)
		return (NULL);
	p->smooth_x = 0;
	p->smooth_y = 0;
	y = -1;
	while (++y < m->map_y)
	{
		x = 0;
		while (x < m->map_x && m->map[y][x] != 'P')
			x++;
		if (m->map[y][x] == 'P')
			break ;
	}
	p->x = x;
	p->y = y;
	return (p);
}

t_collects	*sl_init_collects(void)
{
	t_collects	*c;

	c = (t_collects *)malloc(sizeof(t_collects));
	if (!c)
		return (NULL);
	c->first = NULL;
	return (c);
}

t_exits	*sl_init_exits(void)
{
	t_exits	*e;

	e = (t_exits *)malloc(sizeof(t_exits));
	if (!e)
		return (NULL);
	e->first = NULL;
	return (e);
}

t_pict	*sl_init_pict(void)
{
	t_pict	*i;

	i = (t_pict *)malloc(sizeof(t_pict));
	if (!i)
		return (NULL);
	i->i = NULL;
	i->addr = NULL;
	i->bpp = 0;
	i->line = 0;
	i->endian = 0;
	i->w = 0;
	i->h = 0;
	return (i);
}

t_wins	*sl_init_wins(void)
{
	t_wins	*w;

	w = (t_wins *)malloc(sizeof(t_wins));
	if (!w)
		return (NULL);
	w->mlx = NULL;
	w->win = NULL;
	return (w);
}
