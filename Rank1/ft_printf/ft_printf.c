/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:11:46 by tthwe             #+#    #+#             */
/*   Updated: 2025/12/11 12:51:18 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_writeout(va_list *arg, char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_printnbr(va_arg(*arg, int));
	else if (c == 'u')
		count += ft_printunsigned(va_arg(*arg, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_printhex(va_arg(*arg, unsigned int), c);
	else if (c == 's')
		count += ft_printstr(va_arg(*arg, char*));
	else if (c == 'c')
		count += ft_printchar(va_arg(*arg, int));
	else if (c == 'p')
		count += ft_printptr(va_arg(*arg, void*));
	else if (c == '%')
		count += ft_printchar('%');
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, input);
	while (input[i])
	{
		if (input[i] != '%')
		{
			count += ft_printchar(input[i]);
			i++;
		}
		else
		{
			i++;
			if (!input[i])
				break ;
			count += ft_writeout(&arg, input[i]);
			i++;
		}
	}
	va_end(arg);
	return (count);
}

// int main(void)
// {
//     int result1 = printf(" %p %p ", 0, 0);
// 	int result2 = ft_printf(" %p %p ", 0, 0);
    
//     printf("%d characters were written\n", result1);
// 	ft_printf("%d characters were written\n", result2);
// }