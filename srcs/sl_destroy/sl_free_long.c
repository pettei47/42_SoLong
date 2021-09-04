/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:16:21 by teppei            #+#    #+#             */
/*   Updated: 2021/09/04 20:01:16 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_free_long(t_long *l)
{
	sl_free_map(l->m);
	sl_free_player(l->p);
	sl_free_item_list(l->c);
	sl_free_item_list(l->e);
	free(l->imgs);
	free(l->wins);
	free(l->floor);
	free(l->wall);
	free(l);
}
