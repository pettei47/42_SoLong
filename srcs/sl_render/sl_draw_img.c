/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:53:00 by teppei            #+#    #+#             */
/*   Updated: 2021/09/02 20:57:03 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	sl_get_pixel(t_pict *i, int x, int y)
{
	return (*(int *)(i->addr + (y * i->line + (x * (i->bpp / 8)))));
}

void	sl_set_pixel(t_pict *i, int x, int y, int color)
{
	*(unsigned int *)(i->addr + (y * i->line + x * (i->bpp / 8))) = color;
}

void	sl_draw_img(t_pict *img, t_pict *img2, int x, int y)
{
	t_draw	draw;

	draw.y = 0;
	while (draw.y < DRAW)
	{
		draw.x = 0;
		while (draw.x < DRAW)
		{
			draw.r_x = (float)draw.x / (float)DRAW;
			draw.r_y = (float)draw.y / (float)DRAW;
			draw.pos_x = draw.r_x * img2->w;
			draw.pos_y = draw.r_y * img2->h;
			draw.color = sl_get_pixel(img2, draw.pos_x, draw.pos_y);
			draw.p_data_x = x + draw.x;
			draw.p_data_y = y + draw.y;
			if (draw.color != (int)BLACKCOLOR)
				sl_set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.x++;
		}
		draw.y++;
	}
}
