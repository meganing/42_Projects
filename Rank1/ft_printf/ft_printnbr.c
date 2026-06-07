/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 01:57:14 by tthwe             #+#    #+#             */
/*   Updated: 2025/12/11 10:59:42 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_printstr("-2147483648"));
	if (n < 0)
	{
		count = ft_printchar('-');
		n = -n;
	}
	if (n > 9)
		count += ft_printnbr(n / 10);
	count += ft_printchar((n % 10) + '0');
	return (count);
}
