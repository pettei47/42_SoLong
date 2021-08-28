/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_l_members.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 09:37:14 by teppei            #+#    #+#             */
/*   Updated: 2021/08/28 11:53:48 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_player	*sl_init_player(void)
{
	t_player	*p;

	p = (t_player *)malloc(sizeof(t_player));
	if (!p)
		return (NULL);
	//is_foundいらないかも？
	p->is_found = false;
	p->smooth_x = 0;
	p->smooth_y = 0;
	p->x = 0;
	p->y = 0;
	return (p);
}

t_collects	*sl_init_collects(void)
{
	t_collects	*c;

	c = (t_collects *)malloc(sizeof(t_collects));
	if (!c)
		return (NULL);
	c->first = NULL;
	//is_emptyいらないかも？
	c->is_empty = true;
	return (c);
}

t_exits	*sl_init_exits(void)
{
	t_exits	*e;

	e = (t_exits *)malloc(sizeof(t_exits));
	if (!e)
		return (NULL);
	e->first = NULL;
	//is_emptyいらないかも？
	e->is_empty = true;
	return (e);
}

t_img	*sl_init_img(void)
{
	t_img	*i;

	i = (t_img *)malloc(sizeof(t_img));
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
