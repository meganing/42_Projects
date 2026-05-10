/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 02:37:38 by tthwe             #+#    #+#             */
/*   Updated: 2025/09/10 00:32:16 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static char	*fill_word(char const *s, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	while (s[len] != c && s[len])
	{
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_failalloc(char **s, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(s[i++]);
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	str = (char **)ft_calloc((count_word(s, c) + 1), sizeof(char *));
	while (*s)
	{
		if (*s != c && *s)
		{
			str[j] = fill_word(s, c);
			if (!str[j])
			{
				free_failalloc(str, j);
				return (NULL);
			}
			while (*s != c && *s)
				s++;
			j++;
		}
		else
			s++;
	}
	return (str);
}
