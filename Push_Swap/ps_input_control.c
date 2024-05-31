/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:50:01 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/03/23 16:50:03 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	num_count(char   *s, int *flag, char *max, char *min)
{
	int		index;
	int		res;

	index = 0;
	res = 1;
	if (!ft_isdigit(s[index]) && s[index] != '+' && s[index] != '-')
		return (*flag = 0, 0);
	while (s[index])
	{
		if (s[index] == ' ' && s[index +1] != ' ' && s[index +1])
			res ++;
		if (s[index] == ' ' && (s[index +1] == ' ' || !s[index +1]))
			return (*flag = 0, 0);
		if (!ft_isdigit(s[index]) && s[index] != ' '
			&& s[index] != '-' && s[index] != '+')
			return (*flag = 0, 0);
		if (index == 0 || s[index -1] == ' ')
			if (check_num_len(&s[index], max, min, &index))
				return (*flag = 0, 0);
		index ++;
	}
	return (res);
}

static void	parser(int c, char   **v, t_stack *stack)
{
	int		v_i;
	int		char_i;
	int		stack_i;

	v_i = 1;
	stack_i = 0;
	while (v_i < c)
	{
		char_i = 0;
		while (v[v_i][char_i])
		{
			if (char_i == 0 || v[v_i][char_i -1] == ' ')
			{
				stack->list[stack_i] = ft_atoi(&v[v_i][char_i]);
				stack_i ++;
			}
			char_i ++;
		}
		v_i ++;
	}
}

static int	*check_repeats(t_stack *stack)
{
	size_t	stack_i;
	size_t	check_i;

	stack_i = 0;
	while (stack_i < stack->size -1)
	{
		check_i = stack_i +1;
		while (check_i < stack->size)
		{
			if (stack->list[stack_i] == stack->list[check_i])
				return (free(stack->list), NULL);
			check_i ++;
		}
		stack_i ++;
	}
	return (stack->list);
}

int	*ps_input_control(int c, char   **v, t_stack *s, int flag)
{
	int		index;
	char	*max;
	char	*min;

	index = 1;
	max = ft_itoa(INT_MAX);
	if (!max)
		return (NULL);
	min = ft_itoa(INT_MIN);
	if (!min)
		return (free(max), NULL);
	while (index < c)
	{
		s->size += num_count(v[index], &index, max, min);
		if (!index)
			return (free(max), free(min), NULL);
		index ++;
		if (flag == 1)
			index = c;
	}
	s->list = malloc(s->size * sizeof(int));
	if (!(s->list))
		return (free(max), free(min), NULL);
	parser(c, v, s);
	return (free(max), free(min), check_repeats(s));
}
