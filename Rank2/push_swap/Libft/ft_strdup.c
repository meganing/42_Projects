/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 02:46:42 by tthwe             #+#    #+#             */
/*   Updated: 2025/09/07 02:49:39 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src [i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		strlen;
	char	*dest;

	strlen = ft_strlen(s);
	dest = (char *)malloc((sizeof(char)) * (strlen + 1));
	if (dest == NULL)
		return (0);
	dest = ft_strcpy(dest, s);
	return (dest);
}
