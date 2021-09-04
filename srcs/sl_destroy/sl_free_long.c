/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:16:21 by teppei            #+#    #+#             */
/*   Updated: 2021/09/04 21:16:14 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_free_long(t_long *l)
{
	sl_free_map(l->m);
	free(l->p);
	free(l->c);
	free(l->e);
	free(l->imgs);
	free(l->wins);
	free(l->floor);
	free(l->wall);
	free(l);
}
