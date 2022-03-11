/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_cartesian.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:53:57 by malouvar          #+#    #+#             */
/*   Updated: 2022/01/12 10:41:51 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	parse_col(int i, int j, t_params *params)
{
	t_line	line;
	int		eol;
	int		nb_lines;

	eol = params->eol * 2;
	nb_lines = params->nb_lines * 2;
	line.begin_x = params->map[i][j].x * params->winx / eol + 300;
	line.begin_y = params->map[i][j].y * params->winy / nb_lines + 100;
	line.end_x = params->map[i + 1][j].x * params->winx / eol + 300;
	line.end_y = params->map[i + 1][j].y * params->winy / nb_lines + 100;
	line.color = 0XFF0000;
	return (line);
}

t_line	parse_line(int i, int j, t_params *params)
{
	t_line	line;
	int		eol;
	int		nb_lines;

	eol = params->eol * 2;
	nb_lines = params->nb_lines * 2;
	line.begin_x = params->map[i][j].x * params->winx / eol + 300;
	line.begin_y = params->map[i][j].y * params->winy / nb_lines + 100;
	line.end_x = params->map[i][j + 1].x * params->winx / eol + 300;
	line.end_y = params->map[i][j + 1].y * params->winy / nb_lines + 100;
	line.color = 0X00FF00;
	return (line);
}

t_line	**init_cartesian_col(t_params *params)
{
	int		i;
	int		j;
	t_line	**cartesian;

	i = 0;
	cartesian = malloc(sizeof(t_line *) * params->nb_lines);
	if (!cartesian)
		return (NULL);
	while (params->map[i + 1])
	{
		j = 0;
		cartesian[i] = malloc(sizeof(t_line) * params->eol);
		if (!cartesian[i])
			return (free_struct(cartesian, i), NULL);
		while (j < params->eol)
		{
			cartesian[i][j] = parse_col(i, j, params);
			j++;
		}
		i++;
	}
	cartesian[i] = NULL;
	return (cartesian);
}

t_line	**init_cartesian_lines(t_params *params)
{
	int		i;
	int		j;
	t_line	**cartesian;

	i = 0;
	params->eol = eol_index(params->map[i]);
	cartesian = malloc(sizeof(t_line *) * (params->nb_lines + 1));
	if (!cartesian)
		return (NULL);
	while (params->map[i])
	{
		j = 0;
		cartesian[i] = malloc(sizeof(t_line) * (params->eol));
		if (!cartesian[i])
			return (free_struct(cartesian, i), NULL);
		while (j < params->eol - 1)
		{
			cartesian[i][j] = parse_line(i, j, params);
			j++;
		}
		i++;
	}
	cartesian[i] = NULL;
	return (cartesian);
}
