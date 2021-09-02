/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 22:11:21 by teppei            #+#    #+#             */
/*   Updated: 2021/09/02 20:56:30 by teppei           ###   ########.fr       */
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
			if(l->m->map[y][x] == '1')
				sl_draw_img(l->imgs, l->wall, x * DRAW, y * DRAW);
			else
				sl_draw_img(l->imgs, l->floor, x * DRAW, y * DRAW);
		}
	}
}

int	sl_render_frame(t_long *l)
{
	mlx_do_sync(l->wins->mlx);
	sl_render_map(l);
	mlx_put_image_to_window(l->wins->mlx, l->wins->win, l->imgs->i, 0 ,0);
	return (SUCCESS);
}
