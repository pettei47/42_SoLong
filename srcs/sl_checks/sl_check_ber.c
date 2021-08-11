/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:20:15 by teppei            #+#    #+#             */
/*   Updated: 2021/08/11 16:46:15 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_check_ber(int ac, char **av)
{
	char	*str;
	int		len;

	if (ac != 2)
		sl_error("usage: './solong mapfile_path'\nonly 1 argument is OK");
	str = &av[1][0];
	if (ft_strrchr(av[1], '/'))
		str = ft_strrchr(av[1], '/') + 1;
	len = ft_strlen(str);
	if (len < 5 || ft_strncmp(str + len - 4, ".ber", 5))
		sl_error("file not \".ber\"");
}