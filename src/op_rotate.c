/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:16:59 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/23 16:38:15 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rotate(t_stack *s)
{
	t_frame	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->top->next;
	tmp->prev = NULL;
	s->top->next = NULL;
	s->top->prev = s->bot;
	s->bot->next = s->top;
	s->bot = s->top;
	s->top = tmp;
	stack_update_i(s);
}

void	ra(t_stacks *s)
{
	rotate(s->a);
	ft_cmdadd_back(&s->cmds, RA);
}

void	rb(t_stacks *s)
{
	rotate(s->b);
	ft_cmdadd_back(&s->cmds, RB);
}

void	rr(t_stacks *s)
{
	ra(s);
	rb(s);
	ft_cmdadd_back(&s->cmds, RR);
}

void	rs(t_stacks *s, t_stack *st)
{
	if (st == s->a)
		ra(s);
	else
		rb(s);
}
