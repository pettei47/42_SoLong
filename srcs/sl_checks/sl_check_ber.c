/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:20:15 by teppei            #+#    #+#             */
/*   Updated: 2021/08/16 01:01:24 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**sl_recalloc_map(t_long *l, long y, long b)
{
	char	**ret;
	long	i;
	long	size;

	size = BUF_SIZE * (b + 1);
	ret = (char **)malloc(sizeof(char *) * size);
	if (!ret)
		sl_error("", 0);
	i = -1;
	while (++i < size)
	{
		if (i < y)
			ret[i] = ft_strdup(l->map[i]);
		else
			ret[i] = NULL;
	}
	if (!ret)
		sl_error("", 0);
	ft_free_ptr(l->map);
	return (ret);
}

char	*sl_check_char_closed(char *line, t_long *l, int y, int f)
{
	long		i;
	long		e;
	static long	b;

	if (!line)
		return (NULL);
	if (y + 1 > BUF_SIZE * (b + 1))
		l->map = sl_recalloc_map(l, y, ++b);
	e = 0;
	if (line[0] != '1' || line[l->map_x - 1] != '1')
		e = 1;
	i = 0;
	while (i < l->map_x && line[i])
	{
		if ((y == 0 || f == 1) && line[i] != '1')
			e = 1;
		if (!ft_strchr(MAP_CHAR, line[i++]))
			sl_error("map must have only \""MAP_CHAR"\"", 0);
	}
	if (e != 0)
		sl_error("map must be closed by walls.", 0);
	l->map[y] = ft_strdup(line);
	free(line);
	line = NULL;
	return (line);
}

void	sl_check_map(char *file, t_long *l)
{
	long	fd;
	char	*line;
	long	y;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sl_error("failed to open file", 0);
	y = 0;
	while (get_next_line(fd, &line))
	{
		if (y == 0)
			l->map_x = ft_strlen(line);
		else
		{
			if (ft_strlen(line) != (size_t)l->map_x)
				sl_error("map must be rectangular.", 0);
		}
		line = sl_check_char_closed(line, l, y++, 0);
	}
	close(fd);
	if (ft_strncmp(line, "", 1))
		line = sl_check_char_closed(line, l, y++, 1);
	free(line);
	l->map_y = y;
}

void	sl_check_char_exist(t_long *l)
{
	long	iycp[4];

	iycp[0] = 0;
	iycp[1] = 0;
	iycp[2] = 0;
	iycp[3] = 0;
	while (iycp[2] < (long)ft_strlen(MAP_ELEM))
	{
		if (++iycp[0] == l->map_y)
			sl_error("map must have all of \""MAP_ELEM"\"", 0);
		while (++iycp[1] < l->map_y)
		{
			if (ft_strchr(l->map[iycp[1]], MAP_ELEM[iycp[2]]))
			{
				if (iycp[2] == 0)
					iycp[3] = iycp[1];
				iycp[2]++;
				iycp[1] = 0;
			}
			if (iycp[2] > 0 && iycp[1] != iycp[3] && \
				ft_strchr(l->map[iycp[1]], 'P'))
				sl_error("over two Players", 0);
		}
	}
}

void	sl_check_ber(int ac, char **av, t_long *l)
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
	sl_check_map(av[1], l);
	sl_check_char_exist(l);
}
