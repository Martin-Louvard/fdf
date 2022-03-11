/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:10:20 by malouvar          #+#    #+#             */
/*   Updated: 2021/11/17 17:28:07 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*result;

	size = ft_strlen((char *)s) + 1;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (0);
	ft_memcpy(result, s, size);
	return (result);
}
