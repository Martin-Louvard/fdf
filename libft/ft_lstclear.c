/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malouvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:03:13 by malouvar          #+#    #+#             */
/*   Updated: 2021/11/23 18:07:41 by malouvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*previous;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		del(current->content);
		previous = current;
		current = current->next;
		free(previous);
	}
	*lst = NULL;
}
