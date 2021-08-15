/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_err_freelong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:30:50 by teppei            #+#    #+#             */
/*   Updated: 2021/08/11 18:48:41 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_err_freelong(char *msg, t_long *l)
{
	long	y;

	y = -1;
	while (l->map[++y])
		free(l->map[y]);
	free(l->map);
	sl_error(msg, 0);
}
