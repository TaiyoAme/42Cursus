/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:51 by hehuang           #+#    #+#             */
/*   Updated: 2023/12/26 18:06:58 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	**test;
	int		*converted_tab;
	int		len;
	t_stack	*stack_list;
	t_stack	*stack_b;
	int		j;
	int		end;

	j = 0;
	end = 0;
	len = 0;
	test = create_tab(--argc, ++argv, &len);
	converted_tab = convert_tab(test);
	stack_b = NULL;
	if (converted_tab != NULL && check_duplicate(converted_tab, len))
	{
		stack_list = create_list(converted_tab, len);
		/*printf("\nsize = %d \n", stack_size(stack_list));
		while (stack_list != NULL && j < stack_size(stack_list))
		{
			printf("%d -> ", stack_list -> value);
			stack_list = stack_list -> next;
			j++;
		}*/
		phase_une(10, &stack_list, &stack_b);
		before_push(&stack_list, &stack_b);
		j = 0;
		printf("\nsize = %d \n", stack_size(stack_b));
		while (stack_b != NULL && j < stack_size(stack_b))
		{
			printf("%d[r%d] -> ", stack_b -> value, stack_b -> rank);
			stack_b = stack_b -> next;
			j++;
		}
		end ++;
	}
	else
	{
		printf("Nope \n");
	}
	return (0);
}
