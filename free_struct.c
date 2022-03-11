/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:31:31 by malouvar          #+#    #+#             */
/*   Updated: 2022/01/12 14:33:47 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_struct(t_line **line, int i)
{
	while (i)
	{
		i--;
		free(line[i]);
	}
	free(line);
}

void	end_prog(t_params *params)
{
	mlx_loop_end(params->mlx);
	mlx_destroy_window(params->mlx, params->win);
	mlx_destroy_display(params->mlx);
	free(params->mlx);
	if (params->map)
		free_map(params->map);
	free(params);
}

void	free_cartesian(t_params *params)
{
	int	i;

	i = 0;
	if ((params->cartesian)[0])
	{
		while ((params->cartesian)[0][i])
		{
			free((params->cartesian)[0][i]);
			i++;
		}
		free(params->cartesian[0]);
	}
	if ((params->cartesian)[1])
	{
		i = 0;
		while ((params->cartesian)[1][i])
		{
			free((params->cartesian)[1][i]);
			i++;
		}
		free(params->cartesian[1]);
	}
	end_prog(params);
}

void	free_iso(t_params *params)
{
	int	i;

	i = 0;
	if ((params->iso)[0])
	{
		while ((params->iso)[0][i])
		{
			free((params->iso)[0][i]);
			i++;
		}
		free(params->iso[0]);
	}
	if ((params->iso)[1])
	{
		i = 0;
		while ((params->iso)[1][i])
		{
			free((params->iso)[1][i]);
			i++;
		}
		free(params->iso[1]);
	}
	free_cartesian(params);
}
