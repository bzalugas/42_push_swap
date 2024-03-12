/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:42:32 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/12 13:49:21 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	s->bot->next = s->top;
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
