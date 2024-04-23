/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:49:39 by hehuang           #+#    #+#             */
/*   Updated: 2023/10/25 16:58:53 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (lst && *lst)
	{
		current = *lst;
		if (current -> next)
			ft_lstclear(&(current -> next), del);
		ft_lstdelone(current, del);
	}
	*lst = NULL;
}
