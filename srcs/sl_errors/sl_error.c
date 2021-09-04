/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:54:55 by teppei            #+#    #+#             */
/*   Updated: 2021/09/04 19:33:57 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_error(char *msg, void *p, int f)
{
	if (f == 1)
		sl_free_map((t_map *)p);
	if (f == 2)
		sl_free_long((t_long *)p);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	system("leaks so_long");
	exit (1);
}
