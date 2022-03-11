/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:38:25 by malouvar          #+#    #+#             */
/*   Updated: 2022/01/12 14:42:13 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_utils(char **line, char *elem, char *map)
{
	free(elem);
	free(line);
	free(map);
}

void	free_map(t_coordinates **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_char_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	main(int argc, char **argv)
{
	char			**char_map;
	t_coordinates	**map;
	int				nb_lines;

	if (argc != 2)
		return (1);
	nb_lines = count_lines(argv[1]);
	if (!nb_lines)
		return (1);
	char_map = parse_map(argv[1], nb_lines);
	if (!char_map)
		return (1);
	map = malloc(sizeof(t_coordinates *) * (nb_lines + 1));
	if (!map)
		return (1);
	if (!parse_coordinates(map, char_map, 0, 0))
		return (1);
	draw_fdf(map, nb_lines);
	return (0);
}
