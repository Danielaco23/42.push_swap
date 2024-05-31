/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_p_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:50:33 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/04/22 11:50:36 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa(t_stack *a, t_stack *b, int flag)
{
	t_list	*item;

	if (b->size > 0)
	{
		item = b->lst_a;
		b->lst_a = b->lst_a->next;
		ft_lstadd_front(&a->lst_a, item);
		b->size --;
		a->size ++;
		if (flag == 1)
			ft_putstr_fd(PA, STDOUT_FILENO);
	}
}

void	ps_pb(t_stack *a, t_stack *b, int flag)
{
	t_list	*item;

	if (a->size > 0)
	{
		item = a->lst_a;
		a->lst_a = a->lst_a->next;
		ft_lstadd_front(&b->lst_a, item);
		a->size --;
		b->size ++;
		if (flag == 1)
			ft_putstr_fd(PB, STDOUT_FILENO);
	}
}
