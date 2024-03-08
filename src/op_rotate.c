/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:16:59 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/08 18:09:01 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack *s)
{
	t_frame	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->top->next;
	s->top->next = NULL;
	s->bot->next = s->top;
	s->bot = s->top;
	s->top = tmp;
	stack_update_i(s);
}

void	ra(t_stacks *s)
{
	rotate(s->a);
}

void	rb(t_stacks *s)
{
	rotate(s->b);
}

void	rr(t_stacks *s)
{
	ra(s);
	rb(s);
}
