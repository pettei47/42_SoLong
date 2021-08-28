/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:42:40 by teppei            #+#    #+#             */
/*   Updated: 2021/08/28 11:53:46 by teppei           ###   ########.fr       */
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
	l->p = sl_init_player();
	l->c = sl_init_collects();
	l->e = sl_init_exits();
	l->wins = sl_init_wins();
	l->imgs = sl_init_img();
	l->floor = NULL;
	l->bottom = NULL;
	l->moves = 0;
	l->frame = 0;
	if (!l->p || !l->c || !l->e || !l->wins || !l->imgs)
		sl_error("failed to malloc in init_long", l, 2);
	return (l);
}
