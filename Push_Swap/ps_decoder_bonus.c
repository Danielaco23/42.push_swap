/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_decoder_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:04:05 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/05/09 17:04:07 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	decode_r(char *steps, size_t *i, t_stack *a, t_stack *b)
{
	if (steps[*i] == 'r')
	{
		*i = *i +1;
		if (steps[*i] == 'a')
			ps_rra(a, 0);
		else if (steps[*i] == 'b')
			ps_rrb(b, 0);
		else if (steps[*i] == 'r')
			ps_rrr(a, b, 0);
		else if (steps[*i] == '\n')
			ps_rr(a, b, 0);
		else
			return (free(steps), 1);
	}
	else if (steps[*i] == 'a')
		ps_ra(a, 0);
	else if (steps[*i] == 'b')
		ps_rb(b, 0);
	else
		return (free(steps), 1);
	*i = *i +1;
	return (0);
}

static int	decode_s(char *steps, size_t *i, t_stack *a, t_stack *b)
{
	if (steps[*i] == 'a')
		ps_sa(a, 0);
	else if (steps[*i] == 'b')
		ps_sb(b, 0);
	else if (steps[*i] == 's')
		ps_ss(a, b, 0);
	else
		return (free(steps), 1);
	*i = *i +1;
	return (0);
}

static int	decode_p(char *steps, size_t *i, t_stack *a, t_stack *b)
{
	if (steps[*i] == 'a')
		ps_pa(a, b, 0);
	else if (steps[*i] == 'b')
		ps_pb(a, b, 0);
	else
		return (free(steps), 1);
	*i = *i +1;
	return (0);
}

int	ps_decoder(char *steps, size_t *i, t_stack *a, t_stack *b)
{
	if (steps[*i] == 'r')
	{
		*i = *i +1;
		return (decode_r(steps, i, a, b));
	}
	else if (steps[*i] == 's')
	{
		*i = *i +1;
		return (decode_s(steps, i, a, b));
	}
	else if (steps[*i] == 'p')
	{
		*i = *i +1;
		return (decode_p(steps, i, a, b));
	}
	else
		return (free(steps), 1);
}
