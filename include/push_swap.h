/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:31:57 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/23 18:18:12 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef enum e_op
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

void			sa(t_stacks *s);
void			sb(t_stacks *s);
void			ss(t_stacks *s);

void			push_to(t_stacks *s, t_stack *to);
void			pa(t_stacks *s);
void			pb(t_stacks *s);

void			rs(t_stacks *s, t_stack *st);
void			ra(t_stacks *s);
void			rb(t_stacks *s);
void			rr(t_stacks *s);

void			rrs(t_stacks *s, t_stack *st);
void			rra(t_stacks *s);
void			rrb(t_stacks *s);
void			rrr(t_stacks *s);

/******************************** SORTING *************************************/

void			get_a_target(t_stack *from, t_frame *f);
void			get_b_target(t_stack *from, t_frame *f);
void			get_real_target(t_stacks *s, t_frame *f);
int				cost_push(t_stack *from, t_stack *to, t_frame *f);
void			push_non_sorted(t_stacks *s);
void			get_back_b(t_stacks *s);
void			sort(t_stacks *s);

/********************************** UTILS *************************************/

unsigned int	ft_abs(int n);
long			ft_atol_forward(const char *nptr, int *i);
int				finish_error(t_stacks *s);
int				parse_push_swap(int ac, char *av[], t_stacks *s);
char			*op_to_text(void *content);
int				ft_cmdadd_back(t_list **lst, t_op op);
void			ft_cmdclear(t_list **lst, void (*del)(void *));
int				ft_max_int(int a, int b);
int				ft_min_int(int a, int b);
void			ft_lstremove(t_list **lst, t_list *link, void (*del)(void *));


/******************************* TESTS ****************************************/
void	display_cmds(t_list *cmds);//remove
void	optimize_cmds(t_list *cmds);//remove
bool	sorted(t_stacks *s, t_stack *from, t_frame *f);//remove
void	test_cost_b(t_stacks *s); //remove
void	test_get_b_target(t_stacks *s);//remove
void	test_push_non_sorted(t_stacks *s);//remove
void	test_optimize(void);//remove
void	test_real_target(t_stacks *s);//remove
void	test_sorted(t_stacks *s);//remove


#endif
