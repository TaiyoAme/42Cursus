/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:06:32 by hehuang           #+#    #+#             */
/*   Updated: 2023/10/29 13:44:39 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == c))
		i++;
	return (i);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	in_word;
	int	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (s[i])
	{
		if (!(s[i] == c) && !in_word)
		{
			count++;
			in_word = 1;
		}
		if ((s[i] == c) && in_word)
			in_word = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		j;
	int		in_word;

	j = 0;
	in_word = 0;
	res = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (*s)
	{
		if (!(*s == c) && !in_word)
		{
			res[j] = ft_substr(s, 0, word_len(s, c));
			in_word = 1;
			j++;
		}
		if ((*s == c) && in_word)
			in_word = 0;
		s++;
	}
	res[j] = 0;
	return (res);
}
