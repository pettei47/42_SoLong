/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:18:44 by teppei            #+#    #+#             */
/*   Updated: 2021/08/16 22:30:15 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_long	l;

	sl_init_long(&l);
	sl_check_ber(ac, av, &l);
	for(int i = 0; i < l.map_y; i++)
		printf("[%d]%s\n", i, l.map[i]);
	sl_free_long(&l);
	return (0);
}
