/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:59:40 by malouvar          #+#    #+#             */
/*   Updated: 2021/12/21 15:53:29 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_is_line(char *line, char c )
{
	if (!line)
		return (0);
	while (*line)
	{
		if (*line == c)
			return (1);
		line++;
	}
	return (0);
}

char	*gnl_ft_strdup(char *str)
{
	char	*dup;
	size_t	i;

	if (!str)
		return (NULL);
	dup = malloc(sizeof(char) * (gnl_ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	dup[i] = 0;
	return (dup);
}

char	*gnl_ft_strjoin(char *mem, char *buff)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!mem)
		mem = gnl_ft_strdup("\0");
	if (!buff)
		return (NULL);
	new = malloc(sizeof(char) * (gnl_ft_strlen(mem) + gnl_ft_strlen(buff) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (mem[i])
	{
		new[i] = mem[i];
		i++;
	}
	while (buff[j])
	{
		new[i + j] = buff[j];
		j++;
	}
	new[i + j] = 0;
	return (free(mem), new);
}

char	*ft_save(char *mem)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!mem)
		return (NULL);
	i = 0;
	while (mem[i] && mem[i] != '\n')
		i++;
	if (!mem[i] || !mem[i + 1])
		return (free(mem), NULL);
	i++;
	new = malloc(sizeof(char) * (gnl_ft_strlen(mem + i) + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (mem[i])
	{
		new[j] = mem[i];
		i++;
		j++;
	}
	new[j] = 0;
	return (free(mem), new);
}
