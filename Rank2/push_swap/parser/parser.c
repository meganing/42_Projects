/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 23:46:56 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/03 00:13:15 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_int(char *str)
{
	long	num;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (sign * num < INT_MIN || sign * num > INT_MAX)
			return (0);
		i++;
	}
	if (str[i])
		return (0);
	return (1);
}

static int	has_duplicates(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->data == val)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	error_exit(t_stack *a, t_stack *b)
{
	free_stack(&a);
	free_stack(&b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*node;
	int		val;
	int		i;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
			error_exit(a, NULL);
		val = ft_atoi(argv[i]);
		if (has_duplicates(a, val))
			error_exit(a, NULL);
		node = new_node(val);
		stack_add_bottom(&a, node);
		i++;
	}
	return (a);
}
