/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_r_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:50:44 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/04/22 11:50:45 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_list	*item;

	item = stack->lst_a;
	stack->lst_a = stack->lst_a->next;
	ft_lstadd_back(&stack->lst_a, item);
}

void	ps_ra(t_stack *a, int flag)
{
	if (a->size > 1)
	{
		if (flag == 1)
			ft_putstr_fd(RA, STDOUT_FILENO);
		rotate(a);
	}
}

void	ps_rb(t_stack *b, int flag)
{
	if (b->size > 1)
	{
		if (flag == 1)
			ft_putstr_fd(RB, STDOUT_FILENO);
		rotate(b);
	}
}

void	ps_rr(t_stack *a, t_stack *b, int flag)
{
	if (flag == 1)
		ft_putstr_fd(RR, STDOUT_FILENO);
	rotate(a);
	rotate(b);
}
