/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:51:01 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/05/03 17:51:04 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simple_sorter(t_stack *a, t_stack *b, size_t size);

static void	ps_sort_3(t_stack *a, t_stack *b)
{
	size_t		max;

	max = ps_get_max(a);
	if (ps_get(a, 0) == max)
	{
		ps_ra(a, 1);
		simple_sorter(a, b, 2);
	}
	else if (ps_get(a, 0) == max -1)
	{
		if (ps_get(a, 1) == max)
			ps_rra(a, 1);
		else
			ps_sa(a, 1);
	}
	else if (ps_get(a, 0) == max -2)
	{
		if (ps_get(a, 1) == max)
		{
			ps_sa(a, 1);
			ps_ra(a, 1);
		}
	}
}

static void	ps_sort_4(t_stack *a, t_stack *b)
{
	size_t		dist;

	dist = ps_find_max(a);
	if (dist != 0)
	{
		if (dist == 1)
		{
			if (ps_get(a, 0) <= 2)
				ps_sa(a, 1);
			else
				ps_ra(a, 1);
		}
		else
		{
			ps_rra(a, 1);
			if (ps_find_max(a) != 0)
				ps_rra(a, 1);
		}
	}
	ps_pb(a, b, 1);
	ps_sort_3(a, b);
	ps_pa(a, b, 1);
	ps_ra(a, 1);
}

static void	ps_sort_5(t_stack *a, t_stack *b)
{
	size_t		dist;

	dist = ps_find_max(a);
	if (dist != 0)
	{
		if (dist <= 2)
		{
			if (dist == 2)
				ps_ra(a, 1);
			if (ps_get(a, 0) <= 2)
				ps_sa(a, 1);
			else
				ps_ra(a, 1);
		}
		else
		{
			ps_rra(a, 1);
			if (ps_find_max(a) != 0)
				ps_rra(a, 1);
		}
	}
	ps_pb(a, b, 1);
	ps_sort_4(a, b);
	ps_pa(a, b, 1);
	ps_ra(a, 1);
}

static void	simple_sorter(t_stack *a, t_stack *b, size_t size)
{
	if (size == 2)
	{
		if (ps_get(a, 0) > ps_get(a, 1))
			ps_sa(a, 1);
	}
	else if (size == 3)
		ps_sort_3(a, b);
	else if (size == 4)
		ps_sort_4(a, b);
	else if (size == 5)
		ps_sort_5(a, b);
}

void	ps_sorter(t_stack *a, t_stack *b, size_t size)
{
	if (size <= 5)
		simple_sorter(a, b, size);
	else
	{
		ps_push_b_within_range(a, b);
		ps_push_a_ordered(a, b);
	}
}
