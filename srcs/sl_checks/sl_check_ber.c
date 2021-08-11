/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:20:15 by teppei            #+#    #+#             */
/*   Updated: 2021/08/11 18:02:31 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	sl_check_rect(char *line, int x)
{
	if (ft_strlen(line) != (size_t)x)
		sl_error("map must be rectangular.", 0);
}

void	sl_check_char_closed(char *line, int x, int y, int f)
{
	int	i;
	int	e;

	e = 0;
	if (line[0] != '1' || line[x - 1] != '1')
		e = 1;
	i = -1;
	while (++i < x)
	{
		if ((y == 0 || f == 1) && line[i] != '1')
			e = 1;
		if (!ft_strchr(MAP_CHAR, line[i]))
			sl_error("map must have only \""MAP_CHAR"\"", 0);
	}
	if (e != 0)
		sl_error("map must be closed by walls.", 0);
	printf("line[%d]: %s\n", y, line);
}

void	sl_check_map(char *file)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sl_error("failed to open file", 0);
	y = 0;
	while (get_next_line(fd, &line))
	{
		if (y == 0)
			x = ft_strlen(line);
		else
			sl_check_rect(line, x);
		sl_check_char_closed(line, x, y++, 0);
	}
	sl_check_char_closed(line, x, y, 1);
}

void	sl_check_ber(int ac, char **av)
{
	char	*str;
	int		len;

	if (ac != 2)
		sl_error("usage: './solong mapfile_path'\nonly 1 argument is OK", 0);
	str = &av[1][0];
	if (ft_strrchr(av[1], '/'))
		str = ft_strrchr(av[1], '/') + 1;
	len = ft_strlen(str);
	if (len < 5 || ft_strncmp(str + len - 4, ".ber", 5))
		sl_error("file extention must be \".ber\"", 0);
	sl_check_map(av[1]);
}
