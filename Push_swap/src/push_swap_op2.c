/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:30:30 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/11 14:59:30 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	rotate_stack(t_stack **a, char name)
{
	*a = (*a)-> next;
	if (name)
		printf("r%c\n", name);
}

void	rev_rotate_stack(t_stack **a, char name)
{
	*a = (*a)-> previous;
	if (name)
		printf("rr%c\n", name);
}

void	rotate_stacks(t_stack **a, t_stack **b, t_stack **elm)
{
	rotate_stack(a, 0);
	rotate_stack(b, 0);
	printf("rr\n");
	(*elm)->cost_in_a[1]--;
	(*elm)->cost_in_b[1]--;
}

void	rev_rotate_stacks(t_stack **a, t_stack **b, t_stack **elm)
{
	rev_rotate_stack(a, 0);
	rev_rotate_stack(b, 0);
	printf("rrr\n");
	(*elm)->cost_in_a[1]--;
	(*elm)->cost_in_b[1]--;
}
