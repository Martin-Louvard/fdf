/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:46:51 by malouvar          #+#    #+#             */
/*   Updated: 2022/01/12 14:50:50 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_params	*init_params(t_coordinates **map, int nb_lines)
{
	t_params	*p;

	p = malloc(sizeof(t_params));
	if (!p)
		return (NULL);
	p->mlx = mlx_init();
	if (!p->mlx)
		return (free(p), NULL);
	p->winx = 1920;
	p->winy = 1080;
	p->win = mlx_new_window(p->mlx, p->winx, p->winy, "Fdf");
	if (!p->win)
	{
		mlx_loop_end(p->mlx);
		mlx_destroy_display(p->mlx);
		free(p->mlx);
		return (free(p), NULL);
	}
	p->map = map;
	p->nb_lines = nb_lines;
	(p->cartesian)[0] = NULL;
	(p->cartesian)[1] = NULL;
	(p->iso)[0] = NULL;
	(p->iso)[1] = NULL;
	return (p);
}

int	eol_index(t_coordinates *line)
{
	int	i;

	i = 0;
	while (!line[i].eol)
		i++;
	return (i);
}

void	draw_map(t_params *params, int col)
{
	int	i;
	int	j;

	i = 0;
	while (params->map[i + col])
	{
		j = 0;
		while (j < params->eol - (1 - col))
		{
			draw_line(params, (params->iso)[col][i][j]);
			j++;
		}
		i++;
	}
}

void	draw_fdf(t_coordinates **map, int nb_lines)
{
	t_params	*params;

	params = init_params(map, nb_lines);
	if (!params)
		return (free_map(map));
	mlx_key_hook(params->win, deal_key, params);
	(params->cartesian)[0] = init_cartesian_lines(params);
	if (!((params->cartesian)[0]))
		return (free_cartesian(params));
	(params->cartesian)[1] = init_cartesian_col(params);
	if (!((params->cartesian)[1]))
		return (free_cartesian(params));
	(params->iso)[0] = init_iso_lines(params);
	if (!((params->iso)[0]))
		return (free_iso(params));
	(params->iso)[1] = init_iso_col(params);
	if (!((params->iso)[1]))
		return (free_iso(params));
	draw_map(params, 0);
	draw_map(params, 1);
	mlx_loop(params->mlx);
}
