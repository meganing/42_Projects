/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 03:02:20 by tthwe             #+#    #+#             */
/*   Updated: 2025/09/09 20:59:14 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*num;
	long	nbr;

	nbr = n;
	size = int_len(nbr);
	num = (char *)malloc(sizeof(char) * (size + 1));
	if (!num)
		return (NULL);
	num[size--] = '\0';
	if (nbr < 0)
	{
		num[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		num[0] = '0';
	while (nbr)
	{
		num[size] = (nbr % 10) + '0';
		nbr = nbr / 10;
		size--;
	}
	return (num);
}
