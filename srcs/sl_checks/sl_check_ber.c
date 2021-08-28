/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:20:15 by teppei            #+#    #+#             */
/*   Updated: 2021/08/18 23:22:21 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**sl_recalloc_map(t_map *m, long y, long b)
{
	char	**ret;
	long	i;
	long	size;

	size = BUF_SIZE * (b + 1);
	ret = (char **)malloc(sizeof(char *) * size + 1);
	if (!ret)
		sl_error("failed to malloc at realloc ret", m, 1);
	i = -1;
	while (++i < size)
	{
		if (i < y)
		{
			ret[i] = ft_strdup(m->map[i]);
			if (!ret[i])
				sl_error("failed to strdup at realloc map[i]", m, 1);
		}
		else
		{
			ret[i] = NULL;
		}
	}
	ft_free_ptr(m->map);
	return (ret);
}

char	*sl_check_char_closed(char *line, t_map *m, int y, int f)
{
	long		i;
	static long	b;

	if (!line)
		return (NULL);
	if (y + b + 1 > BUF_SIZE * (b + 1))
		m->map = sl_recalloc_map(m, y, ++b);
	if (line[0] != '1' || line[m->map_x - 1] != '1')
		sl_error("map must be closed by walls.", m, 1);
	i = 0;
	while (i < m->map_x && line[i])
	{
		if ((y == 0 || f == 1) && line[i] != '1')
			sl_error("map must be closed by walls.", m, 1);
		if (!ft_strchr(MAP_CHAR, line[i++]))
			sl_error("map must be only \""MAP_CHAR"\"", m, 1);
	}
	m->map[y] = ft_strdup(line);
	free(line);
	line = NULL;
	if (!(m->map[y]))
		sl_error("failed to strdup at map_set", m, 1);
	return (line);
}

void	sl_check_map(char *file, t_map *m)
{
	long	fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sl_error("failed to open file", m, 1);
	m->map_y = 0;
	while (get_next_line(fd, &line))
	{
		if (m->map_y == 0)
			m->map_x = ft_strlen(line);
		else
		{
			if (ft_strlen(line) != (size_t)m->map_x)
				sl_error("map must be rectangular.", m, 1);
		}
		line = sl_check_char_closed(line, m, m->map_y++, 0);
	}
	close(fd);
	if (ft_strncmp(line, "", 1))
		line = sl_check_char_closed(line, m, m->map_y++, 1);
	free(line);
}

void	sl_check_ber(int ac, char **av, t_map *m)
{
	char	*str;
	int		len;

	if (ac != 2)
		sl_error("usage: './solong mapfile_path'\nonly 1 argument is OK", m, 1);
	str = &av[1][0];
	if (ft_strrchr(av[1], '/'))
		str = ft_strrchr(av[1], '/') + 1;
	len = ft_strlen(str);
	if (len < 5 || ft_strncmp(str + len - 4, ".ber", 5))
		sl_error("file extention must be \".ber\"", m, 1);
	sl_check_map(av[1], m);
	sl_check_char_exist(m);
}
