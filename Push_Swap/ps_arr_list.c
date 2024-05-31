/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arr_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:47:13 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/03/28 11:47:14 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(void *item)
{
	if (!item)
		return ;
	else
		return ;
}

static void	adjust_index(t_stack *a)
{
	t_list	*lst;

	lst = a->lst_a;
	while (lst)
	{
		lst->index--;
		lst = lst->next;
	}
}

static void	add_index(t_stack *a)
{
	t_list	*lst;
	t_list	*min;
	size_t	order;

	order = 1;
	while (order <= a->size)
	{
		lst = a->lst_a;
		min = a->lst_a->next;
		while (lst)
		{
			if (min->index)
				min = lst;
			if (*lst->content < *min->content && !lst->index)
				min = lst;
			lst = lst->next;
		}
		min->index = order++;
	}
	adjust_index(a);
}

int	ps_arr_list(t_stack *a)
{
	size_t	a_i;
	t_list	*item;

	a_i = 0;
	while (a_i < a->size)
	{
		item = ft_lstnew(&(a->list[a_i]));
		if (!item)
			return (ft_lstclear(&(a->lst_a), &error), free(a->list), 1);
		ft_lstadd_back(&(a->lst_a), item);
		a_i ++;
	}
	if (a->size >= 2)
		add_index(a);
	return (1);
}
