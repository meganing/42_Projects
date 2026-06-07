/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:39:06 by tthwe             #+#    #+#             */
/*   Updated: 2025/12/11 12:52:49 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	int		count;
	long	adr;

	count = 0;
	if (ptr == NULL)
		return (ft_printstr("(nil)"));
	count += ft_printstr("0x");
	adr = (unsigned long)ptr;
	count += ft_printhex(adr, 'x');
	return (count);
}
