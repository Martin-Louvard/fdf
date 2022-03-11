/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:08:38 by malouvar          #+#    #+#             */
/*   Updated: 2021/11/23 16:45:20 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_add(char *result, const char *s, char c, unsigned int *pos)
{
	unsigned int	start;

	while (s[*pos] == c && s[*pos])
		(*pos)++;
	start = *pos;
	while (s[*pos] != c && s[*pos])
		(*pos)++;
	result = ft_substr(s, start, (size_t)((*pos) - start));
	result[(*pos) - start] = 0;
	return (result);
}

static int	ft_count(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	pos;
	char			**result;
	int				words;
	int				i;

	words = ft_count((char *)s, c);
	result = malloc(sizeof(char *) * (words + 1));
	i = 0;
	pos = 0;
	if (!result)
		return (NULL);
	while (i < words)
	{
		result[i] = ft_add(result[i], s, c, &pos);
		i++;
	}
	result[words] = NULL;
	return (result);
}
