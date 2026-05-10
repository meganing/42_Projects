/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:41:16 by tthwe             #+#    #+#             */
/*   Updated: 2025/09/07 03:23:49 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && i < size - dst_len - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

// #include <string.h>
// int	 main(void)
// {
// 	char dest[76] = "I am hungry";
// 	char src [76] = "I am full";
// 	printf("length: %zu \n", ft_strlcat(dest, src, 20));
// 	printf("dest : %s \n", dest);

// 	char dest1[76] = "I am hungry";
// 	char src1 [76] = "I am full";
// 	printf("length: %d \n", strlcat(dest1, src1, 20));
// 	printf("dest: %s \n", dest1);
// }