#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int	i;
	int	count;

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
			if (input[i] == 'd' || input[i] == 'i')
				count += ft_printnbr(va_arg(arg, int));
			else if (input[i] == 'u')
				count += ft_printunsigned(va_arg(arg, unsigned int));
			else if (input[i] == 'x' || input[i] == 'X')
				count += ft_printhex(va_arg(arg, unsigned int), input[i]);
			else if (input[i] == 's')
				count += ft_printstr(va_arg(arg, char*));
			else if (input[i] == 'c')
				count += ft_printchar(va_arg(arg, int));
			else if (input[i] == 'p')
				count += ft_printptr(va_arg(arg, void*));
			else if (input[i] == '%')
				count += ft_printchar('%');
			i++;
		}
	}
	va_end(arg);
	return (count);
}