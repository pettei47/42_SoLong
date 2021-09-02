/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_close_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:21:42 by teppei            #+#    #+#             */
/*   Updated: 2021/08/30 21:30:38 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	sl_close_all(t_long *l)
{
	if (l->p->img.i)
		mlx_destroy_image(l->wins->mlx, l->p->img.i);
	if (l->e->img.i)
		mlx_destroy_image(l->wins->mlx, l->e->img.i);
	if (l->c->img.i)
		mlx_destroy_image(l->wins->mlx, l->c->img.i);
	if (l->floor->i)
		mlx_destroy_image(l->wins->mlx, l->floor->i);
	if (l->wall->i)
		mlx_destroy_image(l->wins->mlx, l->wall->i);
	if (l->imgs->i)
		mlx_destroy_image(l->wins->mlx, l->imgs->i);
	if (l->wins->win)
		mlx_destroy_window(l->wins->mlx, l->wins->win);
	sl_free_long(l);
	exit (DONE);
}
