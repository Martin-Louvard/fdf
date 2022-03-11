/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:47:24 by malouvar          #+#    #+#             */
/*   Updated: 2021/11/23 15:06:12 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = 0;
	if (start > s_len)
	{
		result = malloc(sizeof(char));
		result[0] = 0;
		return (result);
	}
	else if (s_len - start < len)
		result = malloc(sizeof(char) * (s_len - start + 1));
	else
		result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (s[start + i] && i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}
