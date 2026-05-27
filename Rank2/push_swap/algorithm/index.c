/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:50:26 by tthwe             #+#    #+#             */
/*   Updated: 2026/05/28 02:50:26 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Finds the smallest data value in the stack that is still larger
** than 'min_val'. Used to walk through values in ascending order.
*/
static int	find_next_min(t_stack *stack, int min_val)
{
	int	result;

	result = INT_MAX;
	while (stack)
	{
		if (stack->data > min_val && stack->data < result)
			result = stack->data;
		stack = stack->next;
	}
	return (result);
}

/*
** Assigns index 0 (smallest) through n-1 (largest) to each node.
** After this, all algorithm logic works on index instead of data.
** Example: data [-5, 42, 7] → index [0, 2, 1]
*/
void	assign_index(t_stack *stack)
{
	int		rank;
	int		current_val;
	t_stack	*node;

	rank = 0;
	current_val = INT_MIN;
	while (rank < stack_size(stack))
	{
		current_val = find_next_min(stack, current_val);
		node = stack;
		while (node)
		{
			if (node->data == current_val)
				node->index = rank;
			node = node->next;
		}
		rank++;
	}
}
