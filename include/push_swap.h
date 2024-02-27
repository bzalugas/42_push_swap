/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:31:57 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/27 13:42:48 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef enum e_stackname
{
	A,
	B,
	C
}			t_stackname;

typedef struct s_frame
{
	int				n;
	int				i;
	struct s_frame	*next;
}				t_frame;

typedef struct	s_stack
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



t_frame	*frame_new(int n, int i, t_frame *next);
t_stack	*stack_new();
int		stack_add(t_stack *stack, int n);
t_frame	*stack_get_frame_i(t_stack *stack, int i);
void	stack_update_i(t_stack *stack);


int		stacks_add_a(t_stacks *stacks, int n);
void	*stacks_clear(t_stacks *stacks);
void	stacks_update_i(t_stacks *stacks, t_stackname stack);

/********************************* OPERATIONS *********************************/

void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

void	rotate(t_frame **top, t_frame **bottom);
void	rr(t_frame **a, t_frame **bot_a, t_frame **b, t_frame **bot_b);

void	rrotate(t_frame **top, t_frame **bottom);
void	rrr(t_frame **a, t_frame **bot_a, t_frame **b, t_frame **bot_b);

#endif
