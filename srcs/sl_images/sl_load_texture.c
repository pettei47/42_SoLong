/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:47:52 by teppei            #+#    #+#             */
/*   Updated: 2021/09/03 02:50:13 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_pict	sl_load_texture(t_long *l, char *path)
{
	t_pict	img;

	img.i = mlx_xpm_file_to_image(l->wins->mlx, path, &img.w, &img.h);
	if (!img.i)
		sl_error("texture file error", l, 2);
	img.addr = mlx_get_data_addr(img.i, &img.bpp, &img.line, &img.endian);
	return (img);
}

t_pict	*sl_set_texture_img(t_long *l, char *path)
{
	t_pict	*i;

	i = (t_pict *)malloc(sizeof(t_pict));
	if (!i)
		sl_error("failed to malloc at load texture", l, 2);
	i->i = mlx_xpm_file_to_image(l->wins->mlx, path, &i->w, &i->h);
	if (!i->i)
		sl_error("texture file error", l, 2);
	i->addr = mlx_get_data_addr(i->i, &i->bpp, &i->line, &i->endian);
	return (i);
}
