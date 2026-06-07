/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 01:40:02 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/06 00:09:51 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	single_cost(int pos, int size)
{
	if (pos > size / 2)
		return (size - pos);
	return (pos);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack->data > max->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

int	get_pos(t_stack *stack, t_stack *node)
{
	int	pos;

	pos = 0;
	while (stack && stack != node)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

t_stack	*find_target(t_stack *a, int val)
{
	t_stack	*target;
	t_stack	*tmp;
	int		best;

	best = INT_MIN;
	target = NULL;
	tmp = a;
	while (tmp)
	{
		if (tmp->data < val && tmp->data > best)
		{
			best = tmp->data;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (!target)
		target = find_max(a);
	return (target);
}

int	calc_cost(t_stack *a, t_stack *b, t_stack *b_node)
{
	t_stack	*target;
	int		size_a;
	int		size_b;
	int		pos_b;
	int		pos_a;

	size_a = stack_size(a);
	size_b = stack_size(b);
	pos_b = get_pos(b, b_node);
	target = find_target(a, b_node->data);
	pos_a = (get_pos(a, target) + 1) % size_a;
	if ((pos_b <= size_b / 2) && (pos_a <= size_a / 2))
		return (ft_max(pos_b, pos_a));
	if ((pos_b > size_b / 2) && (pos_a > size_a / 2))
		return (ft_max(size_b - pos_b, size_a - pos_a));
	return (single_cost(pos_b, size_b) + single_cost(pos_a, size_a));
}
