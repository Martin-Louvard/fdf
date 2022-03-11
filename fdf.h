/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:59:39 by malouvar          #+#    #+#             */
/*   Updated: 2022/01/12 14:42:12 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	z;
	int	eol;
}	t_coordinates;

typedef struct s_line
{
	int	begin_x;
	int	begin_y;
	int	end_x;
	int	end_y;
	int	color;
}	t_line;

typedef struct s_params
{
	t_coordinates	**map;
	void			*mlx;
	void			*win;
	int				winx;
	int				winy;
	int				nb_lines;
	int				eol;
	t_line			**cartesian[2];
	t_line			**iso[2];
}	t_params;

int				count_lines(char *file);
char			**parse_map(char *file, int nb_lines);
int				count_col(char **line);
t_coordinates	parse_x_y_z(int x, int y, char *z);
int				parse_coordinates(t_coordinates **map, char **char_map,
					int i, int j);
int				deal_key(int key, t_params *params);
int				draw_line(t_params *params, t_line line);
void			draw_fdf(t_coordinates **map, int nb_lines);
t_params		*init_params(t_coordinates **map, int nb_lines);
void			draw_map(t_params *params, int col);
int				eol_index(t_coordinates *line);
t_line			**init_iso_col(t_params *params);
t_line			**init_iso_lines(t_params *params);
t_line			parse_iso_col(int i, int j, t_params *params, t_line **iso);
t_line			parse_iso_line(int i, int j, t_params *params, t_line **iso);
t_line			**init_cartesian_lines(t_params *params);
t_line			**init_cartesian_col(t_params *params);
t_line			parse_line(int i, int j, t_params *params);
t_line			parse_col(int i, int j, t_params *params);
void			free_params(t_params *params);
void			free_map(t_coordinates **map);
void			free_utils(char **line, char *elem, char *map);
void			free_struct(t_line **iso, int i);
void			free_char_map(char **map);
void			end_prog(t_params *params);
void			free_cartesian(t_params *params);
void			free_iso(t_params *params);
#endif
