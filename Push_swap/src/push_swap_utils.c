/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:19:24 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/09 15:15:53 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	int		slen;
	int		i;
	char	*res;

	i = 0;
	slen = ft_strlen(s);
	res = malloc((slen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i <= slen)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

int	ft_tabcat(char **dest, char *src)
{
	char	**w_tab;
	int		tab_len;
	int		i;

	i = 0;
	tab_len = count_words(src);
	w_tab = ft_split(src);
	while (i < tab_len)
	{
		*dest++ = ft_strdup(w_tab[i]);
		i++;
	}
	return (tab_len - 1);
}

int	is_number(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	while (++i < len)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	i;
	int	res;

	neg = 1;
	res = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n'
		|| nptr[i] == '\t' || nptr[i] == '\f'
		|| nptr[i] == '\v' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + nptr[i] - '0';
		i++;
	}
	return (res * neg);
}

t_stack	*stack_new(int content)
{
	t_stack	*res;
	int		*cost_a;
	int		*cost_b;

	res = malloc(sizeof(t_stack) * 1);
	if (!res)
		return (NULL);
	cost_a = malloc(sizeof(int) * 2);
	if (!cost_a)
		return (NULL);
	cost_b = malloc(sizeof(int) * 2);
	if (!cost_b)
		return (NULL);
	cost_a[0] = 0;
	cost_a[1] = 0;
	cost_b[0] = 0;
	cost_b[1] = 0;
	res -> value = content;
	res -> rank = 0;
	res -> cost_in_a = cost_a;
	res -> cost_in_b = cost_b;
	return (res);
}
