/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_num_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:44:31 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/03/26 13:44:33 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_pos(char   *s, char *max)
{
	int		i;
	int		res;
	int		flag;

	i = 0;
	res = 0;
	flag = 0;
	while (s[i] == '0')
		i ++;
	while (s[i] && s[i] != ' ' && s[i] != '+'
		&& s[i] != '-')
	{
		if (res < 10)
		{
			if (((s[i] > max[res] && flag == 0)) || flag == 1)
				flag = 1;
			else if (s[i] < max[res])
				flag = 2;
		}
		res ++;
		i ++;
	}
	if ((res > 10) || (res == 10 && flag == 1) || (s[i] != ' ' && s[i]))
		return (1);
	return (0);
}

static int	check_neg(char   *s, char *min)
{
	int		i;
	int		res;
	int		flag;

	i = 0;
	res = 0;
	flag = 0;
	while (s[i] == '0')
		i ++;
	while (s[i] && s[i] != ' ' && s[i] != '+'
		&& s[i] != '-')
	{
		if (res < 10)
		{
			if (((s[i] > min[res +1] && flag == 0)) || flag == 1)
				flag = 1;
			else if (s[i] < min[res +1])
				flag = 2;
		}
		res ++;
		i ++;
	}
	if ((res > 10) || (res == 10 && flag == 1) || (s[i] != ' ' && s[i]))
		return (1);
	return (0);
}

int	check_num_len(char   *s, char *max, char *min, int *index)
{
	if (s[0] == '+' || s[0] == '-')
	{
		if (s[1] < '0' || s[1] > '9')
			return (1);
		if (*index > 0 && (s[-1] != ' '))
			return (1);
	}
	if (s[0] == '-')
		return ((*index)++, check_neg(s +1, min));
	else if (s[0] == '+')
		return ((*index)++, check_pos(s +1, max));
	return (check_pos(s, max));
}

int	ps_is_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}
