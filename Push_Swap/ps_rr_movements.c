/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rr_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:50:54 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/04/22 11:50:55 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_list	*item;
	t_list	*item2;

	item2 = stack->lst_a;
	while (item2->next->next)
		item2 = item2->next;
	item = item2->next;
	item2->next = NULL;
	ft_lstadd_front(&stack->lst_a, item);
}

void	ps_rra(t_stack *a, int flag)
{
	if (a->size > 1)
	{
		if (flag == 1)
			ft_putstr_fd(RRA, STDOUT_FILENO);
		reverse_rotate(a);
	}
}

void	ps_rrb(t_stack *b, int flag)
{
	if (b->size > 1)
	{
		if (flag == 1)
			ft_putstr_fd(RRB, STDOUT_FILENO);
		reverse_rotate(b);
	}
}

void	ps_rrr(t_stack *a, t_stack *b, int flag)
{
	if (flag == 1)
		ft_putstr_fd(RRR, STDOUT_FILENO);
	reverse_rotate(a);
	reverse_rotate(b);
}
