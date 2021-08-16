/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_char_exist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 22:04:32 by teppei            #+#    #+#             */
/*   Updated: 2021/08/16 22:24:16 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_check_elements(t_long *l, char c)
{
	long	i;

	i = 0;
	while (++i < l->map_y)
	{
		if (ft_strchr(l->map[i], c))
			return ;
	}
	sl_error("map must have all of \""MAP_ELEM"\"", l, 1);
}

void	sl_check_p(t_long *l)
{
	long	i;
	long	cnt_p;

	i = 0;
	cnt_p = 0;
	while (++i < l->map_y)
		cnt_p += ft_strchr_cnt(l->map[i], 'P');
	if (cnt_p != 1)
		sl_error("must be 1 Player", l, 1);
}

void	sl_check_char_exist(t_long *l)
{
	long	i;
	long	len;

	sl_check_p(l);
	i = -1;
	len = (long)ft_strlen(MAP_ELEM);
	while (++i < len)
		sl_check_elements(l, MAP_ELEM[i]);
}
