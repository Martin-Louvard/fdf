/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:55:27 by malouvar          #+#    #+#             */
/*   Updated: 2022/01/12 11:22:15 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_lines(char *file)
{
	int		count;
	int		fd;
	char	*buff;

	count = 0;
	fd = open(file, O_RDONLY);
	buff = malloc(sizeof(char *));
	if (!buff)
		return (0);
	while (read(fd, buff, 1) > 0)
	{
		if (buff[0] == '\n')
			count++;
	}
	close(fd);
	free(buff);
	return (count);
}

char	**parse_map(char *file, int nb_lines)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (free_char_map(map), NULL);
		}
		map[i] = line;
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

int	count_col(char **line)
{
	int	count;

	count = 0;
	while (!ft_strchr(line[count], '\n'))
		count++;
	if (line[count][0] != '\n')
		count++;
	return (count);
}

t_coordinates	parse_x_y_z(int x, int y, char *z)
{
	t_coordinates	point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(z);
	point.eol = 0;
	return (free(z), point);
}

int	parse_coordinates(t_coordinates **map, char **char_map, int i, int j)
{
	char			**line;
	int				nb_col;

	while (char_map[i])
	{
		line = ft_split(char_map[i], ' ');
		nb_col = count_col(line);
		map[i] = malloc(sizeof(t_coordinates) * (nb_col + 1));
		if (!map[i])
		{
			free_map(map);
			return (free_char_map(char_map), 0);
		}
		j = 0;
		while (j < nb_col)
		{
			map[i][j] = parse_x_y_z(j, i, line[j]);
			j++;
		}
		map[i][j].eol = 1;
		free_utils(line, line[j], char_map[i]);
		i++;
	}
	map[i] = NULL;
	return (free(char_map), 1);
}
