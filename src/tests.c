/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 07:08:10 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/18 07:49:05 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	test_cost_b(t_stacks *s)
{
	t_frame *top;
	int		cost;
	int		i;

	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		cost = cost_push_b(s, top, top->target);
		ft_printf("cost for %d=%d\n", top->n, cost);
		top = top->next;
	}
	i = (s->a->size / 2) + 1;
	while (--i > 0)
		pb(s);
	ft_putendl_fd("\n\n", 1);
	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		cost = cost_push_b(s, top, top->target);
		ft_printf("cost for %d=%d\n", top->n, cost);
		top = top->next;
	}
	rrr(s);
	ft_putendl_fd("\n\n", 1);
	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		cost = cost_push_b(s, top, top->target);
		ft_printf("cost for %d=%d\n", top->n, cost);
		top = top->next;
	}
}
