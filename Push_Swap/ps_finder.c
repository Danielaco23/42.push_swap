/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:04:59 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/05/03 18:05:01 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ps_get(t_stack *lst, size_t pos)
{
	t_list	*item;

	item = lst->lst_a;
	while (pos > 0 && item->next)
	{
		item = item->next;
		pos --;
	}
	return (item->index);
}

size_t	ps_find_max(t_stack *lst)
{
	t_list	*item;
	size_t	res[2];
	size_t	pos;

	item = lst->lst_a;
	pos = 0;
	res[0] = 0;
	res[1] = 0;
	while (item)
	{
		if (item->index >= res[0])
		{
			res[0] = item->index;
			res[1] = pos;
		}
		pos ++;
		item = item->next;
	}
	return (res[1]);
}

size_t	ps_get_max(t_stack *lst)
{
	t_list	*item;
	size_t	res;

	item = lst->lst_a;
	res = 0;
	while (item)
	{
		if (item->index >= res)
			res = item->index;
		item = item->next;
	}
	return (res);
}
