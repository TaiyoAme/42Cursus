/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:57:59 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/11 16:56:18 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap_stack(t_stack **a, char name)
{
	int	tmp_val;
	int	tmp_rank;

	tmp_val = (*a)->value;
	tmp_rank = (*a)->rank;
	if (*a && (*a)-> next)
	{
		(*a)->rank = (*a)->next->rank;
		(*a)->value = (*a)->next->value;
		(*a)->next->rank = tmp_rank;
		(*a)->next->value = tmp_val;
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
	if (stack_size(*from) == 0)
		from = NULL;
}
