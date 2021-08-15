/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:18:44 by teppei            #+#    #+#             */
/*   Updated: 2021/08/16 01:02:57 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_long	l;

	sl_init_long(&l);
	sl_check_ber(ac, av, &l);
	printf("map_y:%ld\n", l.map_y);
	for(int i = 0; i < l.map_y; i++)
		printf("[%d]%s\n", i, l.map[i]);
	return (0);
}
