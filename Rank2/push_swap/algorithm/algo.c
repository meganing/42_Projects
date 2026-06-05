/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 01:59:52 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/06 00:09:44 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_stack	*find_cheapest(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;
	t_stack	*tmp;
	int		min_cost;
	int		cost;

	cheapest = b;
	min_cost = calc_cost(a, b, b);
	tmp = b->next;
	while (tmp)
	{
		cost = calc_cost(a, b, tmp);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

static void	rotate_both(t_stack **a, t_stack **b,
				t_stack *best, t_stack *pivot)
{
	int	pos_b;
	int	pos_a;
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	pos_b = get_pos(*b, best);
	pos_a = get_pos(*a, pivot);
	while (*b != best && *a != pivot)
	{
		if (pos_b <= size_b / 2 && pos_a <= size_a / 2)
			rr(a, b);
		else if (pos_b > size_b / 2 && pos_a > size_a / 2)
			rrr(a, b);
		else
			break ;
		pos_b = get_pos(*b, best);
		pos_a = get_pos(*a, pivot);
	}
}

static void	finish_rotations(t_stack **a, t_stack **b,
				t_stack *best, t_stack *pivot)
{
	int	size_b;
	int	size_a;
	int	pos;

	size_b = stack_size(*b);
	size_a = stack_size(*a);
	pos = get_pos(*b, best);
	while (*b != best)
	{
		if (pos <= size_b / 2)
			rb(b);
		else
			rrb(b);
		pos = get_pos(*b, best);
	}
	pos = get_pos(*a, pivot);
	while (*a != pivot)
	{
		if (pos <= size_a / 2)
			ra(a);
		else
			rra(a);
		pos = get_pos(*a, pivot);
	}
}

void	push_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*best;
	t_stack	*target;
	t_stack	*pivot;

	best = find_cheapest(*a, *b);
	target = find_target(*a, best->data);
	if (target->next)
		pivot = target->next;
	else
		pivot = *a;
	rotate_both(a, b, best, pivot);
	finish_rotations(a, b, best, pivot);
	pa(a, b);
}
