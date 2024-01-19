/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:30:30 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/18 16:09:23 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **a, char name)
{
	if (*a)
	{
		*a = (*a)-> next;
		if (name)
		{
			write(1, "r", 1);
			write(1, &name, 1);
			write(1, "\n", 1);
		}
	}
}

void	rev_rotate_stack(t_stack **a, char name)
{
	if (*a)
	{
		*a = (*a)-> previous;
		if (name)
		{
			write(1, "rr", 2);
			write(1, &name, 1);
			write(1, "\n", 1);
		}
	}
}

void	rotate_stacks(t_stack **a, t_stack **b, t_stack **elm, int name)
{
	rotate_stack(a, 0);
	rotate_stack(b, 0);
	if (name)
		write(1, "rr\n", 3);
	(*elm)->cost_in_a[1]--;
	(*elm)->cost_in_a[3]--;
}

void	rev_rotate_stacks(t_stack **a, t_stack **b, t_stack **elm, int name)
{
	rev_rotate_stack(a, 0);
	rev_rotate_stack(b, 0);
	if (name)
		write(1, "rrr\n", 4);
	(*elm)->cost_in_a[1]--;
	(*elm)->cost_in_a[3]--;
}
