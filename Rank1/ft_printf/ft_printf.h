/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:11:54 by tthwe             #+#    #+#             */
/*   Updated: 2025/12/11 12:26:04 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"

int	ft_printf(const char *input, ...);
int	ft_printptr(void *ptr);
int	ft_printchar(char c);
int	ft_printhex(unsigned long n, char format);
int	ft_printnbr(int n);
int	ft_printstr(char *s);
int	ft_printunsigned(unsigned int n);

#endif
