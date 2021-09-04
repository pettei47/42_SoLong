/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_l_members.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 11:04:48 by teppei            #+#    #+#             */
/*   Updated: 2021/09/04 20:03:27 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_free_player(t_player *p)
{
	if (!p)
		return ;
	free(p);
}

void	sl_free_item_list(t_item_list *i)
{
	t_item	*target;
	t_item	*tmp;

	if (!i)
		return ;
	target = i->first;
	while (target)
	{
		tmp = target->next;
		free(target);
		target = tmp;
	}
	free(i);
}
