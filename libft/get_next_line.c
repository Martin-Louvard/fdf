/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:11:58 by malouvar          #+#    #+#             */
/*   Updated: 2021/12/21 16:01:42 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1000

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;
	char		*buff;
	long		len;

	if (fd < 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	len = 1;
	while (len && !ft_is_line(mem, '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buff[len] = 0;
		mem = gnl_ft_strjoin(mem, buff);
	}
	line = gnl_ft_strdup(mem);
	mem = ft_save(mem);
	return (free(buff), line);
}
