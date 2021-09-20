/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:42:40 by teppei            #+#    #+#             */
/*   Updated: 2021/09/20 16:59:37 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_long	*sl_init_long(t_map *m)
{
	t_long	*l;

	l = (t_long *)malloc(sizeof(t_long));
	if (!l)
		sl_error("failed to malloc in init_long", m, 1);
	l->m = m;
	l->p = sl_init_player(m);
	l->en = sl_init_enemy();
	l->enemy = false;
	l->c = NULL;
	l->e = NULL;
	l->wins = sl_init_wins();
	l->imgs = sl_init_pict();
	l->floor = NULL;
	l->wall = NULL;
	l->moves = 0;
	l->frame = 0;
	l->enemy_mv = 1;
	if (!l->p || !l->en || !l->wins || !l->imgs)
		sl_error("failed to malloc in init_long", l, 2);
	return (l);
}
