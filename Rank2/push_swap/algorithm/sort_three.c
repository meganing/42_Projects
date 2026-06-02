/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:50:26 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/03 02:18:33 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	small_top(t_stack **a, int mid, int bot)
{
	if (mid > bot)
	{
		sa(a);
		ra(a);
	}
}

static void	second_top(t_stack **a, int mid, int bot)
{
	if (mid > bot)
		rra(a);
	else
		sa(a);
}

static void	big_top(t_stack **a, int mid, int bot)
{
	if (mid > bot)
	{
		sa(a);
		rra(a);
	}
	else
		ra(a);
}

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->index;
	mid = (*a)->next->index;
	bot = (*a)->next->next->index;
	if (top < mid && mid < bot)
		return ;
	if (top < mid && top < bot)
		small_top(a, mid, bot);
	else if ((top < mid && top > bot) || (top > mid && top < bot))
		second_top(a, mid, bot);
	else
		big_top(a, mid, bot);
}
