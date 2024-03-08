/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:31:57 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/08 18:10:13 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_frame
{
	int				n;
	int				i;
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
}				t_stacks;

/***************************** STACKS HANDLING ********************************/

t_frame			*frame_new(int n, int i, t_frame *next);
t_stack			*stack_new(void);
int				stack_add_back(t_stack *stack, int n);
t_frame			*stack_get_i(t_stack *stack, int i);
void			stack_update_i(t_stack *stack);
t_frame			*stack_get_n(t_stack *s, int n);
int				stack_score(t_stack *s);

t_stacks		stacks_new(void);
int				stacks_add_a(t_stacks *stacks, int n);
void			*stacks_clear(t_stacks *stacks);

/********************************* OPERATIONS *********************************/

void			swap(t_stack *s);
void			sa(t_stacks *stacks);
void			sb(t_stacks *stacks);
void			ss(t_stacks *stacks);

void			pa(t_stacks *stacks);
void			pb(t_stacks *stacks);

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

#endif
