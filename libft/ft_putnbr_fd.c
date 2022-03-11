/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <malouvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:33:27 by malouvar          #+#    #+#             */
/*   Updated: 2021/11/18 14:45:41 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse(long n, int fd)
{
	if (n < 10)
		ft_putchar_fd((n + 48), fd);
	else
	{
		recurse(n / 10, fd);
		recurse(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = (long)n * -1;
	}
	else
		nb = (long)n;
	recurse(nb, fd);
}
