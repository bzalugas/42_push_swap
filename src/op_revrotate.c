/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:42:32 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/11 10:55:29 by bazaluga         ###   ########.fr       */
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
}

void	rrb(t_stacks *s)
{
	rrotate(s->b);
}

void	rrr(t_stacks *s)
{
	rra(s);
	rrb(s);
}
