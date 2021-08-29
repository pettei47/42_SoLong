/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:24:56 by teppei            #+#    #+#             */
/*   Updated: 2021/08/28 14:08:09 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_init_map(t_map *m)
{
	long	i;

	m->map_x = -1;
	m->map_y = -1;
	m->map = (char **)malloc(sizeof(char *) * (BUF_SIZE + 1));
	if (!(m->map))
		sl_error("failed to malloc at init t_long", m, 0);
	i = -1;
	while (++i < BUF_SIZE)
		m->map[i] = NULL;
}
