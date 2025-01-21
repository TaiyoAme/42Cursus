/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_occur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:52:37 by hehuang           #+#    #+#             */
/*   Updated: 2024/11/28 16:55:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_occur(char	*str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (!str)
		return (i);
	while (str[++i])
	{
		if (str[i] == c)
			count ++;
	}
	return (count);
}
