/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_s_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:51:08 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/04/22 11:51:10 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_list	*first_item;
	t_list	*second_item;

	first_item = stack->lst_a;
	second_item = stack->lst_a->next;
	first_item->next = second_item->next;
	second_item->next = first_item;
	stack->lst_a = second_item;
}

void	ps_sa(t_stack *a, int flag)
{
	if (a->size >= 2)
	{
		if (flag == 1)
			ft_putstr_fd(SA, STDOUT_FILENO);
		swap(a);
	}
}

void	ps_sb(t_stack *b, int flag)
{
	if (b->size >= 2)
	{
		if (flag == 1)
			ft_putstr_fd(SB, STDOUT_FILENO);
		swap(b);
	}
}

void	ps_ss(t_stack *a, t_stack *b, int flag)
{
	if (flag == 1)
		ft_putstr_fd(SS, STDOUT_FILENO);
	swap(a);
	swap(b);
}
