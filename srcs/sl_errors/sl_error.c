/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:54:55 by teppei            #+#    #+#             */
/*   Updated: 2021/08/16 06:53:00 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_error(char *msg, t_long *l, int f)
{
	if (f > 0)
		sl_free_long(l);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit (FAILURE);
}
