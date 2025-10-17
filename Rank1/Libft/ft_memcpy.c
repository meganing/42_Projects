/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:02:05 by tthwe             #+#    #+#             */
/*   Updated: 2025/08/28 21:02:09 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	while (n > 0)
	{
		*(dptr++) = *(sptr++);
		n--;
	}
	return (dest);
}
