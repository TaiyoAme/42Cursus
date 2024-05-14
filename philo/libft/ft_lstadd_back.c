/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:48:23 by hehuang           #+#    #+#             */
/*   Updated: 2023/10/25 16:07:43 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *elt)
{
	t_list	*current;

	current = ft_lstlast(lst[0]);
	if (!current)
		lst[0] = elt;
	else if (elt)
		current -> next = elt;
}
