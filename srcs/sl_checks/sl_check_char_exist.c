/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_char_exist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:04:32 by teppei            #+#    #+#             */
/*   Updated: 2021/08/18 23:22:42 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_check_elements(t_map *m, char c)
{
	long	i;

	i = 0;
	while (++i < m->map_y)
	{
		if (ft_strchr(m->map[i], c))
			return ;
	}
	sl_error("map must have all of \""MAP_ELEM"\"", m, 1);
}

void	sl_check_p(t_map *m)
{
	long	i;
	long	cnt_p;

	i = 0;
	cnt_p = 0;
	while (++i < m->map_y)
		cnt_p += ft_strchr_cnt(m->map[i], 'P');
	if (cnt_p != 1)
		sl_error("map must be 1 Player", m, 1);
}

void	sl_check_char_exist(t_map *m)
{
	long	i;
	long	len;

	sl_check_p(m);
	i = -1;
	len = (long)ft_strlen(MAP_ELEM);
	while (++i < len)
		sl_check_elements(m, MAP_ELEM[i]);
}
