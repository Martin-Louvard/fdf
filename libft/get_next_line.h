/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:21:04 by malouvar          #+#    #+#             */
/*   Updated: 2021/12/21 14:54:31 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_save(char *mem);
char	*get_next_line(int fd);
int		ft_is_line(char *line, char c);
char	*gnl_ft_strjoin(char *mem, char *buff);
char	*gnl_ft_strdup(char *str);

#endif
