/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:12:13 by malouvar          #+#    #+#             */
/*   Updated: 2021/11/24 09:54:31 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (!c)
		return ((char *)s + i);
	while (i >= 1 && s[i - 1] != (char)c)
		i--;
	if (s[i - 1] == (char)c)
		return ((char *)s + i - 1);
	else
		return (NULL);
}
