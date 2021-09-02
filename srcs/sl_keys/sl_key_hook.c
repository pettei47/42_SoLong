/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 21:11:37 by teppei            #+#    #+#             */
/*   Updated: 2021/08/30 21:20:49 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_other_keys(int key, t_long *l)
{
	if (l->m->map[(int)(l->p->y)][(int)(l->p->x + 1)] != '1' && key == D)
	{
		l->p->x += 1;
		l->moves++;
	}
	
}

int	sl_key_hook(int key, t_long *l)
{
	if (l->m->map[(int)(l->p->y - 1)][(int)(l->p->x)] != '1' && key == W)
	{
		l->p->y -= 1;
		l->moves++;
	}
	else if (l->m->map[(int)(l->p->y)][(int)(l->p->x - 1)] != '1' && key == A)
	{
		l->p->x -= 1;
		l->moves++;
	}
	else if (l->m->map[(int)(l->p->y + 1)][(int)(l->p->x)] != '1' && key == S)
	{
		l->p->y += 1;
		l->moves++;
	}
	sl_other_keys(key, m);
	return (SUCCESS);
}