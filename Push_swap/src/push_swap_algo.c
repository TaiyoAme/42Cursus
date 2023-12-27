/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:06:05 by hehuang           #+#    #+#             */
/*   Updated: 2023/12/27 18:27:48 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	phase_une(int tier, t_stack **a, t_stack **b)
{
	int	a_size;
	int	b_size;

	while (stack_size(*a) > 3)
	{
		a_size = stack_size(*a);
		b_size = stack_size(*b);
		while (stack_size(*a) > (((a_size / tier)) * (tier - 2)) + (a_size % tier))
		{
			if ((*a)->rank <= (a_size / tier) + b_size)
				push_stack(a, b, 'b');
			else if ((*a)->rank <= (((a_size / tier) * 2) + b_size))
			{
				push_stack(a, b, 'b');
				rotate_stack(b, 'b');
			}
			else
				rotate_stack(a, 'a');
		}
		if (stack_size(*a) < tier * 2)
			phase_une(3, a, b);
	}
}

int	fastest_way(t_stack **stack_list, int rank)
{
	t_stack	*from_top;
	t_stack	*from_bottom;

	from_top = (*stack_list)-> next ;
	from_bottom = (*stack_list)-> previous;
	while (from_top -> rank != (*stack_list)-> rank)
	{
		if (from_top -> rank == rank)
			return (1);
		else if (from_bottom -> rank == rank)
			return (2);
		from_top = from_top -> next;
		from_bottom = from_bottom -> previous;
	}
	return (0);
}

void	set_stack(t_stack **b, int rank)
{
	int	swap;
	int	rev_rot;

	swap = 1;
	rev_rot = 1;
	while (((*b)->rank != rank) && (!rev_rot && !swap))
	{
		if (rev_rot || swap)
		{
			rev_rot = 0;
			swap = 0;
		}
		if ((*b)->rank < (*b)->next->rank)
		{
			swap = 1;
			swap_stack(b, 'b');
		}
		if ((*b)->rank < (*b)->previous->rank)
		{
			rev_rot = 1;
			rev_rotate_stack(b, 'b');
		}
	}
}

void	before_push(t_stack **a, t_stack **b)
{
	int		low_a_rank;
	t_stack	*current;

	low_a_rank = (*a)-> rank;
	current = (*a)-> next;
	while (current -> rank != (*a)-> rank)
	{
		if (current -> rank < low_a_rank)
			low_a_rank = current -> rank;
		current = current -> next;
	}
	while (*b)
	{
		set_stack(b, --low_a_rank);
		push_stack(b, a, 'a');
	}
	/*while (*b)
	{
		if (fastest_way(b, --low_a_rank) == 1)
			while ((*b)-> rank != low_a_rank)
				rotate_stack(b, 'b');
		else
			while ((*b)-> rank != low_a_rank)
				rev_rotate_stack(b, 'b');
		push_stack(b, a, 'a');
	}
	while ((*b)-> rank != low_a_rank - 1)
	{
		if ((*a)-> rank != low_a_rank)
		{
			if (fastest_way(a, low_a_rank) && fastest_way(b, low_a_rank - 1))
				rotate_stacks(a, b);
			else if (!fastest_way(a, low_a_rank) && !fastest_way(b, low_a_rank - 1))
				rev_rotate_stacks(a, b);
			else if (fastest_way(a, low_a_rank) && !fastest_way(b, low_a_rank - 1))
			{
				rotate_stack(a, 'a');
				rev_rotate_stack(b, 'b');
			}
			else if (!fastest_way(a, low_a_rank) && fastest_way(b, low_a_rank - 1))
			{
				rev_rotate_stack(a, 'a');
				rotate_stack(b, 'b');
			}
		}
	}*/
}
