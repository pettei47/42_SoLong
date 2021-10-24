/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:20:15 by teppei            #+#    #+#             */
/*   Updated: 2021/10/25 00:26:03 by teppei           ###   ########.fr       */
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

bool	sl_check_rect(char *line, t_map *m, long rect)
{
	long	len;

	len = ft_strlen(line);
	if (rect == 1 && (len > 0 || m->map_y == 0))
		return (false);
	if (rect == 0 && len != m->map_x)
		return (false);
	return (true);
}

void	sl_check_map(char *file, t_map *m, long rect)
{
	long	fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		sl_error("failed to open file", m, 1);
	m->map_y = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) == 0)
			rect = 1;
		if (m->map_y == 0)
			m->map_x = ft_strlen(line);
		if (!sl_check_rect(line, m, rect))
			sl_error("map must be rectangular.", m, 1);
		if (rect == 0)
			line = sl_check_char_closed(line, m, m->map_y++, 0);
		else
			free(line);
		line = NULL;
	}
	close(fd);
	if (ft_strncmp(line, "", 1))
		line = sl_check_char_closed(line, m, m->map_y++, 1);
	free(line);
}

void	sl_check_ber(char **av, t_map *m)
{
	char	*str;
	int		len;

	str = &av[1][0];
	if (ft_strrchr(av[1], '/'))
		str = ft_strrchr(av[1], '/') + 1;
	len = ft_strlen(str);
	if (len < 5 || ft_strncmp(str + len - 4, ".ber", 5))
		sl_error("file extention must be \".ber\"", m, 1);
	sl_check_map(av[1], m, 0);
	sl_check_char_exist(m);
}
