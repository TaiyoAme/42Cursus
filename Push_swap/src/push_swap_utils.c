/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:19:24 by hehuang           #+#    #+#             */
/*   Updated: 2024/01/19 17:26:50 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_tabcat(char ***dest, char *src, int *index)
{
	char	**w_tab;
	int		tab_len;
	int		i;

	i = 0;
	tab_len = count_words(src);
	w_tab = ft_split(src);
	while (i < tab_len)
	{
		(*dest)[*index] = ft_strdup(w_tab[i]);
		i++;
		(*index)++;
	}
	(*index)--;
}

int	is_number(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (++i < len)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}
	return (1);
}

long long	ft_atol(const char *nptr)
{
	int			neg;
	int			i;
	long long	res;

	neg = 1;
	res = 0;
	i = 0;
	while (nptr[i] == '0' || nptr[i] == ' ' || nptr[i] == '\n'
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
	if (i > 11 || res * neg > 2147483647 || res * neg < -2147483648)
		return (2147483648);
	return (res * neg);
}

t_stack	*stack_new(int content)
{
	t_stack	*res;
	int		*cost_a;

	res = malloc(sizeof(t_stack) * 1);
	if (!res)
		return (NULL);
	cost_a = malloc(sizeof(int) * 4);
	if (!cost_a)
		return (NULL);
	cost_a[0] = 0;
	cost_a[1] = 0;
	cost_a[2] = 0;
	cost_a[3] = 0;
	res -> value = content;
	res -> rank = 0;
	res -> cost_in_a = cost_a;
	return (res);
}
