/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-l <dgomez-l@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:45:54 by dgomez-l          #+#    #+#             */
/*   Updated: 2024/03/22 14:45:56 by dgomez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./Libft/libft.h"
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

typedef struct s_stack
{
	int				*list;
	size_t			size;
	t_list			*lst_a;
}	t_stack;

/* FORMAT, LIMITS AND PARSING CONTROLS */

int			*ps_input_control(int c, char   **v, t_stack *s, int flag);
int			check_num_len(char   *s, char *max, char *min, int *index);
int			ps_is_sorted(t_list *a);
int			ps_arr_list(t_stack *stack);

/* MOVEMENTS */

/* SWAPS: */

/* a[0] <-> a[1] */
void		ps_sa(t_stack *a, int flag);
/* b[0] <-> b[1] */
void		ps_sb(t_stack *b, int flag);
/* a[0] <-> a[1] && b[0] <-> b[1] */
void		ps_ss(t_stack *a, t_stack *b, int flag);

/* PUSHES: */

/* b[0] -> a[0] */
void		ps_pa(t_stack *a, t_stack *b, int flag);
/* a[0] -> b[0] */
void		ps_pb(t_stack *a, t_stack *b, int flag);

/* ROTATES: */

/* Shift a up */
void		ps_ra(t_stack *a, int flag);
/* Shift b up */
void		ps_rb(t_stack *b, int flag);
/* Shift both up */
void		ps_rr(t_stack *a, t_stack *b, int flag);

/* REVERSE ROTATES: */

/* Shift a down */
void		ps_rra(t_stack *a, int flag);
/* Shift b down */
void		ps_rrb(t_stack *b, int flag);
/* Shift both down */
void		ps_rrr(t_stack *a, t_stack *b, int flag);

/* SOLVING */

/* Controls the stack sorting */
void		ps_sorter(t_stack *a, t_stack *b, size_t size);
/* Gets the item in number pos in the stack */
size_t		ps_get(t_stack *lst, size_t pos);
/* Finds the highest item in the stack and returns its position */
size_t		ps_find_max(t_stack *lst);
/* Finds the highest item in the stack and returns its value */
size_t		ps_get_max(t_stack *lst);

/* K SORT */

void		ps_push_b_within_range(t_stack *a, t_stack *b);
void		ps_push_a_ordered(t_stack *a, t_stack *b);

/* CHECKER */

int			ps_decoder(char *steps, size_t *i, t_stack *a, t_stack *b);

#endif
