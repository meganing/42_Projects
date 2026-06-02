/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:16:55 by tthwe             #+#    #+#             */
/*   Updated: 2025/09/07 03:09:22 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (!src || !dest)
		return (NULL);
	temp1 = (unsigned char *)src;
	temp2 = (unsigned char *)dest;
	if (dest < src)
	{
		while (n > 0)
		{
			*(temp2++) = *(temp1++);
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			temp2[n] = temp1[n];
		}
	}
	return (dest);
}
