/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:32:08 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/05/09 12:32:10 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	c(void *a)
{
	if (!a)
		return ;
	return ;
}

static char	*stdin_reader(void)
{
	ssize_t		nbytes;
	char		*res;
	char		buf[257];

	res = NULL;
	nbytes = read(STDIN_FILENO, buf, 256);
	while (nbytes > 0)
	{
		buf[nbytes] = '\0';
		res = ft_strjoin(res, buf);
		nbytes = read(STDIN_FILENO, buf, 256);
	}
	if (nbytes < 0 && res != NULL)
		return (free(res), NULL);
	else if (nbytes < 0)
		return (NULL);
	while (res && res[nbytes])
	{
		if (res[nbytes] != 'a' && res[nbytes] != 'b'
			&& res[nbytes] != 'p' && res[nbytes] != 'r'
			&& res[nbytes] != 's' && res[nbytes] != '\n')
			return (free(res), NULL);
		nbytes ++;
	}
	return (res);
}

static int	checker(t_stack *a, t_stack *b)
{
	char	*steps;
	size_t	i;

	steps = stdin_reader();
	if (!steps)
		return (1);
	i = 0;
	while (steps[i])
	{
		if (ps_decoder(steps, &i, a, b))
			return (free(steps), 1);
		if (steps[i] != '\n' && steps[i] != '\0')
			return (free(steps), 1);
		i ++;
	}
	free(steps);
	if (!b->lst_a && ps_is_sorted(a->lst_a))
		return (1);
	return (0);
}

int	main(int argc, char   **argv)
{
	t_stack		a;
	t_stack		b;

	a.lst_a = NULL;
	a.size = 0;
	b.lst_a = NULL;
	b.size = 0;
	if (argc < 2)
		return (0);
	if (!ps_input_control(argc, argv, &a, 0))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!ps_arr_list(&a))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (ps_is_sorted(a.lst_a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else if (checker(&a, &b))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	ft_lstclear(&(a.lst_a), &c);
	ft_lstclear(&(b.lst_a), &c);
	return (free(a.list), 0);
}
