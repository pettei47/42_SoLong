/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_l_members.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:04:48 by teppei            #+#    #+#             */
/*   Updated: 2021/08/28 11:50:22 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_free_player(t_player *p)
{
	if (!p)
		return ;
	free(p);
}

void	sl_free_collects(t_collects *c)
{
	t_collect	*target;
	t_collect	*tmp;

	if (!c)
		return ;
	target = c->first;
	while (target)
	{
		tmp = target->next;
		free(target);
		target = tmp;
	}
	free(c);
}

void	sl_free_exits(t_exits *e)
{
	t_exit	*target;
	t_exit	*tmp;

	if(!e)
		return ;
	target = e->first;
	while (target)
	{
		tmp = target->next;
		free(target);
		target = tmp;
	}
	free(e);
}

void	sl_free_img(t_img *i)
{
	if (!i)
		return ;
	free(i->addr);
	free(i->i);
	free(i);
}

void	sl_free_wins(t_wins *w)
{
	if (!w)
		return ;
	free(w->mlx);
	free(w->win);
	free(w);
}
