/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:50:26 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/03 00:19:12 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	assign_indexes(t_stack *a)
{
	t_stack	*outer;
	t_stack	*inner;
	int		index;

	outer = a;
	while (outer)
	{
		index = 0;
		inner = a;
		while (inner)
		{
			if (inner->data < outer->data)
				index++;
			inner = inner->next;
		}
		outer->index = index;
		outer = outer->next;
	}
}

void	rotate_to_min(t_stack **a)
{
	t_stack	*min_node;
	int		pos;
	int		size;

	min_node = find_min(*a);
	size = stack_size(*a);
	pos = get_pos(*a, min_node);
	while (*a != min_node)
	{
		if (pos <= size / 2)
			ra(a);
		else
			rra(a);
		pos = get_pos(*a, min_node);
	}
}
