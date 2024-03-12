/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:03:53 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/12 13:51:27 by bazaluga         ###   ########.fr       */
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
	s->top->prev = tmp;
	tmp->next = s->top;
	tmp->prev = NULL;
	s->top->i++;
	tmp->i--;
	if (s->bot == tmp)
		s->bot = s->top;
	s->top = tmp;
}

void	sa(t_stacks *s)
{
	swap(s->a);
	ft_cmdadd_back(&s->cmds, SA);
}

void	sb(t_stacks *s)
{
	swap(s->b);
	ft_cmdadd_back(&s->cmds, SB);
}

void	ss(t_stacks *s)
{
	sa(s);
	sb(s);
	ft_cmdadd_back(&s->cmds, SS);
}
