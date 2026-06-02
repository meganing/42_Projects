/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 02:11:46 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/03 02:11:51 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		sa(a);
		return ;
	}
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	while (stack_size(*a) > 3)
		pb(a, b);
	sort_three(a);
	while (*b)
		push_cheapest(a, b);
	rotate_to_min(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	b = NULL;
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	assign_indexes(a);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
