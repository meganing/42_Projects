/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:14:46 by tthwe             #+#    #+#             */
/*   Updated: 2025/09/09 22:17:30 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoin)
		return (NULL);
	while (*s1)
	{
		strjoin[i++] = *(s1++);
	}
	while (*s2)
	{
		strjoin[i++] = *(s2++);
	}
	strjoin[i] = '\0';
	return (strjoin);
}
// int main(void)
// {
// 	char *str1 = "I am a girl";
// 	char *str2 = "I love eating";
// 	char *str3;
// 	str3 = ft_strjoin(str1, str2);
// 	if (str3)
//     {
//         printf("%s\n", str3);
//         free(str3);
//     }
//     return 0;
// }