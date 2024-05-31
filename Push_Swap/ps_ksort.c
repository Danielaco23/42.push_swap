/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ksort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:01:06 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/05/08 15:01:08 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	dist_to_current(t_list *lst, size_t i)
{
	size_t	count;

	count = 0;
	while (lst && lst->index != i)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	ps_push_a_ordered(t_stack *a, t_stack *b)
{
	size_t		dist_rb;
	size_t		dist_rrb;

	while (b->size > 0)
	{
		dist_rb = dist_to_current(b->lst_a, b->size -1);
		dist_rrb = (b->size - dist_rb);
		if (dist_rb <= dist_rrb)
		{
			while (b->lst_a->index != b->size -1)
				ps_rb(b, 1);
			ps_pa(a, b, 1);
		}
		else
		{
			while (b->lst_a->index != b->size - 1)
				ps_rrb(b, 1);
			ps_pa(a, b, 1);
		}
	}
}

void	ps_push_b_within_range(t_stack *a, t_stack *b)
{
	size_t		range;

	range = (ft_sqrt(a->size)) * 133 / 100;
	while (a->size)
	{
		if (a->lst_a->index <= b->size)
		{
			ps_pb(a, b, 1);
			if (b->size > 1 && b->lst_a->index < b->lst_a->next->index)
				ps_sb(b, 1);
		}
		else if (a->lst_a->index <= b->size + range)
		{
			ps_pb(a, b, 1);
			if (a->size > 1 && !(a->lst_a->index <= b->size + range))
				ps_rr(a, b, 1);
			else if (a->size > 1)
				ps_rb(b, 1);
		}
		else
			ps_ra(a, 1);
	}
}
