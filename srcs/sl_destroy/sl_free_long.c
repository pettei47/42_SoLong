/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:16:21 by teppei            #+#    #+#             */
/*   Updated: 2021/08/29 18:11:04 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_free_l_img(t_pict *i)
{
	if (!i)
		return ;
	free(i->i);
	free(i);
}

void	sl_free_long(t_long *l)
{
	sl_free_map(l->m);
	sl_free_player(l->p);
	sl_free_collects(l->c);
	sl_free_exits(l->e);
	sl_free_l_img(l->imgs);
	sl_free_wins(l->wins);
	sl_free_img(l->floor);
	sl_free_img(l->wall);
	free(l);
}
