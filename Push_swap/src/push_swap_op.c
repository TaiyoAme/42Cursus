/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:57:59 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/18 16:10:29 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **a, char name)
{
	int	tmp_val;
	int	tmp_rank;

	
	if (*a && (*a)-> next)
	{
		tmp_val = (*a)->value;
		tmp_rank = (*a)->rank;
		(*a)->rank = (*a)->next->rank;
		(*a)->value = (*a)->next->value;
		(*a)->next->rank = tmp_rank;
		(*a)->next->value = tmp_val;
	}
	if (name)
	{
		write(1, "s", 1);
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	swap_stacks(t_stack **a, t_stack **b, int name)
{
	swap_stack(a, 0);
	swap_stack(b, 0);
	if (name)
		write(1, "ss\n", 3);
}

void	push_stack(t_stack **from, t_stack **to, char name)
{
	t_stack	*node_kept;

	if (*from)
	{
		node_kept = *from;
		delfirst(from);
		addfirst(to, node_kept);
		if (name)
		{
			write(1, "p", 1);
			write(1, &name, 1);
			write(1, "\n", 1);
		}
	}
	if (stack_size(*from) == 0)
		from = NULL;
}
