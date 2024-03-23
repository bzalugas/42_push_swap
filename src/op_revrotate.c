/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:42:32 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/23 16:38:09 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rrotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->bot->next = s->top;
	s->top->prev = s->bot;
	s->top = s->bot;
	s->bot = s->bot->prev;
	s->top->prev = NULL;
	s->bot->next = NULL;
	stack_update_i(s);
}

void	rra(t_stacks *s)
{
	rrotate(s->a);
	ft_cmdadd_back(&s->cmds, RRA);
}

void	rrb(t_stacks *s)
{
	rrotate(s->b);
	ft_cmdadd_back(&s->cmds, RRB);
}

void	rrr(t_stacks *s)
{
	rra(s);
	rrb(s);
	ft_cmdadd_back(&s->cmds, RRR);
}

void	rrs(t_stacks *s, t_stack *st)
{
	if (st == s->a)
		rra(s);
	else
		rrb(s);
}
