/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 02:08:58 by tthwe             #+#    #+#             */
/*   Updated: 2025/09/07 02:40:54 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!little[i])
		return ((char *)big);
	while (big[j] && j < len)
	{
		while (big[j + i] == little[i] && little[i] && big[j + i]
			&& j + i < len)
		{
			i++;
		}
		if (little[i] == '\0')
			return ((char *)&big[j]);
		j++;
		i = 0;
	}
	return (NULL);
}
