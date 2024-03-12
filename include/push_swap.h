/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:31:57 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/12 15:00:42 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef enum	e_op
{
	S,
	R,
	RRO,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_op;

typedef struct s_frame
{
	int				n;
	int				i;
	struct s_frame	*target;
	struct s_frame	*prev;
	struct s_frame	*next;
}				t_frame;

typedef struct s_stack
{
	t_frame	*top;
	t_frame	*bot;
	int		size;
}				t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		total;
	t_list	*cmds;
}				t_stacks;

/***************************** STACKS HANDLING ********************************/

t_frame			*frame_new(int n, int i, t_frame *prev, t_frame *next);
t_stack			*stack_new(void);
int				stack_add_back(t_stack *stack, int n);
t_frame			*stack_get_i(t_stack *stack, int i);
void			stack_update_i(t_stack *stack);
t_frame			*stack_get_n(t_stack *s, int n);
int				stack_score(t_stack *s);
t_frame			*stack_get_max(t_stack *s);
t_frame			*stack_get_min(t_stack *s);

t_stacks		stacks_new(void);
int				stacks_add_a(t_stacks *stacks, int n);
void			*stacks_clear(t_stacks *stacks);

/********************************* OPERATIONS *********************************/

void			swap(t_stack *s);
void			sa(t_stacks *s);
void			sb(t_stacks *s);
void			ss(t_stacks *s);

void			pa(t_stacks *s);
void			pb(t_stacks *s);

void			rotate(t_stack *s);
void			ra(t_stacks *s);
void			rb(t_stacks *s);
void			rr(t_stacks *s);

void			rrotate(t_stack *s);
void			rra(t_stacks *s);
void			rrb(t_stacks *s);
void			rrr(t_stacks *s);

/******************************** SORTING *************************************/

/********************************** UTILS *************************************/

unsigned int	ft_abs(int n);
long			ft_atol_forward(const char *nptr, int *i);
int				finish_error(t_stacks *s);
int				parse_push_swap(int ac, char *av[], t_stacks *s);
int				ft_cmdadd_back(t_list **lst, t_op op);
void			ft_cmdclear(t_list **lst, void (*del)(void *));
int				ft_max_int(int a, int b);
int				ft_min_int(int a, int b);

#endif
