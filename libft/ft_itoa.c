/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:57:17 by malouvar          #+#    #+#             */
/*   Updated: 2021/11/18 13:54:49 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_size(long n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		size;
	long	nb;

	size = ft_find_size((long)n);
	string = malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	string[size] = 0;
	if (n < 0)
	{
		string[0] = '-';
		nb = (long)n * -1;
	}
	else
		nb = (long)n;
	while (nb >= 10)
	{
		string[--size] = (nb % 10) + 48;
		nb /= 10;
	}
	string[--size] = (nb % 10) + 48;
	return (string);
}
