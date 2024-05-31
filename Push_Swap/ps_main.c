/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:13:11 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/03/23 16:13:14 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	c(void *a)
{
	if (!a)
		return ;
	return ;
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
		return (1);
	if (!ps_input_control(argc, argv, &a, 0))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!ps_arr_list(&a))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (ps_is_sorted(a.lst_a))
		return (ft_lstclear(&(a.lst_a), &c), free(a.list), 1);
	if (a.size > 1)
		ps_sorter(&a, &b, a.size);
	ft_lstclear(&(a.lst_a), &c);
	ft_lstclear(&(b.lst_a), &c);
	free(a.list);
	return (0);
}

/*int main(void)
{
	char	*str[2];
	char	numbers[10];
	numbers[9] = 0;
	int		fd = open("nogit_combs.txt", O_RDONLY);

	str[0] = "push_swap";
	str[1] = &numbers[0];
	int num = read(fd, numbers, 9);
	while (num)
	{
		ft_putstr_fd("\n", 1);
		push_swap(2, str);
		num = read(fd, numbers, 1);
		num = read(fd, numbers, 9);
	}
}*/
