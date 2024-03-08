/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:03:53 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/08 18:09:53 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *s)
{
	t_frame	*tmp;

	if (s->size < 2)
		return ;
	tmp = s->top->next;
	s->top->next = s->top->next->next;
	tmp->next = s->top;
	s->top->i++;
	tmp->i--;
	if (s->bot == tmp)
		s->bot = s->top;
	s->top = tmp;
}

void	sa(t_stacks *stacks)
{
	swap(stacks->a);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->b);
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
