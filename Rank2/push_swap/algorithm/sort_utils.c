/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:50:26 by tthwe             #+#    #+#             */
/*   Updated: 2026/05/28 02:50:26 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
** Rotates a until the node with index 0 is at the top.
** Uses ra if min is in the first half, rra if in the second half.
*/
void	rotate_min_to_top(t_stack **a)
{
	t_stack	*cur;
	int		min_pos;
	int		size;

	cur = *a;
	min_pos = 0;
	size = stack_size(*a);
	while (cur->index != 0)
	{
		min_pos++;
		cur = cur->next;
	}
	if (min_pos <= size / 2)
		while ((*a)->index != 0)
			ra(a);
	else
		while ((*a)->index != 0)
			rra(a);
}
