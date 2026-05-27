/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 03:26:57 by tthwe             #+#    #+#             */
/*   Updated: 2026/05/28 03:26:57 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi_check(const char *str, int *result)
{
	long long	nb;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > 2147483648LL)
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	nb *= sign;
	if (nb > 2147483647LL || nb < -2147483648LL)
		return (0);
	*result = (int)nb;
	return (1);
}
