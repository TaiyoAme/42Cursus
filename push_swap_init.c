/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:15:47 by hehuang           #+#    #+#             */
/*   Updated: 2023/12/22 20:14:05 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <string.h>

char	**create_tab(int argc, char **argv, int *count)
{
	int		i;
	int		j;
	char	**res;

	i = -1;
	j = 0;
	while (++i < argc)
		*count += count_words(argv[i]);
	res = malloc((*count + 1) * sizeof(char *));
	i = 0;
	while (i < *count)
	{
		if (count_words(argv[j]) > 1)
			i += ft_tabcat(&res[i], argv[j++]);
		else
			res[i] = ft_strdup(argv[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

int	*convert_tab(char **str_tab)
{
	int	len;
	int	i;
	int	*res;
	int	number_error;

	len = 0;
	i = -1;
	number_error = 0;
	while (str_tab[len])
		len++;
	res = malloc(len * sizeof(int));
	while (++i < len && !number_error)
	{
		if (is_number(str_tab[i]))
			res[i] = ft_atoi(str_tab[i]);
		else
		{
			number_error = 1;
			res[i] = 0;
		}
	}
	i = -1;
	i++;//REPLACE WITH FREE STR_TAB
	if (number_error)
		return (NULL);//FUNCTION TO HANDLE INT ERR
	return (res);
}

int	check_duplicate(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	add_min_rank(t_stack *stack_list, int rank)
{
	t_stack	*min;
	t_stack	*current;

	min = stack_list;
	current = stack_list -> next;
	while (current != NULL)
	{
		if (min->rank)
			min = current;
		if (!current -> rank && current -> value < min -> value)
			min = current;
		current = current -> next;
		if (current == stack_list)
			current = NULL;
	}
	min -> rank = rank;
}

t_stack	*create_list(int *tab, int len)
{
	t_stack	*res;
	t_stack	*current;
	t_stack	*tmp;
	int		i;

	i = 1;
	res = stack_new(tab[0]);
	current = res;
	while (i < len)
	{
		tmp = stack_new(tab[i]);
		tmp -> previous = current;
		current -> next = tmp;
		current = current -> next;
		i++;
	}
	current -> next = res;
	i = 0;
	while (++i < len + 1)
		add_min_rank(res, i);
	res -> previous = current;
	return (res);
}
