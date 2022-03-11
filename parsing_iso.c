/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_iso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:55:44 by malouvar          #+#    #+#             */
/*   Updated: 2022/01/12 14:34:50 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	parse_iso_line(int i, int j, t_params *params, t_line **iso)
{
	t_line	line;

	if (j > 0)
	{
		line.begin_x = iso[i][j - 1].end_x;
		line.begin_y = iso[i][j - 1].end_y;
	}
	else
	{
		line.begin_x = (params->cartesian)[0][i][j].begin_x
			- (params->cartesian)[0][i][j].begin_y + 400;
		line.begin_y = ((params->cartesian)[0][i][j].begin_x
				+ (params->cartesian)[0][i][j].begin_y) / 2
			- (params->map[i][j].z * 2);
	}
	line.end_x = (params->cartesian)[0][i][j].end_x
		- (params->cartesian)[0][i][j].end_y + 400;
	line.end_y = ((params->cartesian)[0][i][j].end_x
			+ (params->cartesian)[0][i][j].end_y) / 2
		- (params->map[i][j + 1].z * 2);
	if (!params->map[i][j].z && !params->map[i][j + 1].z)
		line.color = 0XFFFFFF;
	else
		line.color = 0X00FF00;
	return (line);
}

t_line	parse_iso_col(int i, int j, t_params *params, t_line **iso)
{
	t_line	line;

	if (i > 0)
	{
		line.begin_x = iso[i - 1][j].end_x;
		line.begin_y = iso[i - 1][j].end_y;
	}
	else
	{
		line.begin_x = (params->cartesian)[1][i][j].begin_x
			- (params->cartesian)[1][i][j].begin_y + 400;
		line.begin_y = ((params->cartesian)[1][i][j].begin_x
				+ (params->cartesian)[1][i][j].begin_y) / 2
			- (params->map[i][j].z * 2);
	}
	line.end_x = (params->cartesian)[1][i][j].end_x
		- (params->cartesian)[1][i][j].end_y + 400;
	line.end_y = ((params->cartesian)[1][i][j].end_x
			+ (params->cartesian)[1][i][j].end_y) / 2
		- (params->map[i + 1][j].z * 2);
	if (!params->map[i][j].z && !params->map[i + 1][j].z)
		line.color = 0XFFFFFF;
	else
		line.color = 0X00FF00;
	return (line);
}

t_line	**init_iso_lines(t_params *params)
{
	int		i;
	int		j;
	t_line	**iso;

	i = 0;
	iso = malloc(sizeof(t_line *) * (params->nb_lines + 1));
	if (!iso)
		return (NULL);
	while (params->map[i])
	{
		j = 0;
		iso[i] = malloc(sizeof(t_line) * params->eol);
		if (!iso[i])
			return (free_struct(iso, i), NULL);
		while (j < params->eol - 1)
		{
			iso[i][j] = parse_iso_line(i, j, params, iso);
			j++;
		}
		i++;
	}
	iso[i] = NULL;
	return (iso);
}

t_line	**init_iso_col(t_params *params)
{
	int		i;
	int		j;
	t_line	**iso;

	i = 0;
	iso = malloc(sizeof(t_line *) * params->nb_lines);
	if (!iso)
		return (NULL);
	while (params->map[i + 1])
	{
		j = 0;
		iso[i] = malloc(sizeof(t_line) * params->eol);
		if (!iso[i])
			return (free_struct(iso, i), NULL);
		while (j < params->eol)
		{
			iso[i][j] = parse_iso_col(i, j, params, iso);
			j++;
		}
		i++;
	}
	iso[i] = NULL;
	return (iso);
}
