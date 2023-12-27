/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:57:59 by hehuang           #+#    #+#             */
/*   Updated: 2023/12/20 18:36:43 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap_stack(t_stack **a, char name)
{
	t_stack	*tmp;

	tmp = *a;
	if (*a && (*a)-> next)
	{
		tmp = (*a)-> next;
		(*a)-> next = tmp -> next;
		tmp -> previous = (*a)-> previous;
		(*a)-> previous = tmp;
		tmp -> next = *a;
	}
	if (name)
		printf("s%c\n", name);
}

void	swap_stacks(t_stack **a, t_stack **b)
{
	swap_stack(a, 0);
	swap_stack(b, 0);
	printf("ss\n");
}

void	push_stack(t_stack **from, t_stack **to, char name)
{
	t_stack	*node_kept;

	if (*from)
	{
		node_kept = *from;
		delfirst(from);
		addfirst(to, node_kept);
		printf("p%c\n", name);
	}
}
