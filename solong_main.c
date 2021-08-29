/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:18:44 by tep]pei            #+#    #+#             */
/*   Updated: 2021/08/29 16:24:08 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "solong.h"
/*
void	sl_loop(t_data *d)
{
	mlx_loop_hook(l->wins->mlx, render_next_frame, mem);
	mlx_hook(l->wins->win, 2, 1L << 0, key_hook, mem);
	mlx_hook(l->wins->win, 33, 1L << 5, close_clean, mem);
	mlx_loop(l->wins->mlx);
}
*/

int	main(int ac, char **av)
{
	t_long	*l;
	t_map	map;

	(void)l;
	sl_init_map(&map);
	sl_check_ber(ac, av, &map);
	for(int i = 0; i < map.map_y; i++)
		printf("[%d]%s\n", i, map.map[i]);
	l = sl_init_long(&map);
	//sl_loop(&l);
	sl_free_long(l);
	return (0);
}
