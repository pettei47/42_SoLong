/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:24:56 by teppei            #+#    #+#             */
/*   Updated: 2021/08/15 23:55:47 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_init_long(t_long *l)
{
	long	i;

	l->map_x = -1;
	l->map_y = -1;
	l->map = (char **)malloc(sizeof(char *) * (BUF_SIZE + 1));
	if (!(l->map))
		sl_error("failed to malloc at init t_long", 1);
	i = -1;
	while (++i < BUF_SIZE)
		l->map[i] = NULL;
}
