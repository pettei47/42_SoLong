/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:11:37 by teppei            #+#    #+#             */
/*   Updated: 2021/09/04 21:26:23 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_put_move_cli(int key, t_long *l)
{
	if (key != W && key != A && key != S && key != D)
		return ;
	l->moves++;
	ft_putnbr_fd(l->moves, 1);
	if (key == W)
		ft_putendl_fd(": W", 1);
	if (key == A)
		ft_putendl_fd(": A", 1);
	if (key == S)
		ft_putendl_fd(": S", 1);
	if (key == D)
		ft_putendl_fd(": D", 1);
}

int	sl_key_hook(int key, t_long *l)
{
	long	x;
	long	y;

	x = l->p->x;
	y = l->p->y;
	if (key == ESC)
		sl_close_all(l);
	if (l->m->map[(int)(y - 1)][(int)x] != '1' && key == W)
		l->p->y -= 1;
	else if (l->m->map[(int)y][(int)(x - 1)] != '1' && key == A)
		l->p->x -= 1;
	else if (l->m->map[(int)(y + 1)][(int)x] != '1' && key == S)
		l->p->y += 1;
	if (l->m->map[(int)y][(int)(x + 1)] != '1' && key == D)
		l->p->x += 1;
	if (y != l->p->y || x != l->p->x)
		sl_put_move_cli(key, l);
	return (SUCCESS);
}
