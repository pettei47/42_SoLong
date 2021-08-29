/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 06:41:28 by teppei            #+#    #+#             */
/*   Updated: 2021/08/28 11:46:06 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_free_map(t_map *m)
{
	long	i;

	i = -1;
	while (++i < m->map_y)
		free(m->map[i]);
	free(m->map);
}