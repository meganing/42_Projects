/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:41:09 by tthwe             #+#    #+#             */
/*   Updated: 2025/09/08 02:48:57 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char const c, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstr;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (!set || !s1)
		return (NULL);
	while (s1[start] && check_set(s1[start], set))
		start++;
	while (start < end && s1[end - 1] && check_set(s1[end - 1], set))
		end--;
	trimstr = ft_substr(s1, start, end - start);
	return (trimstr);
}
