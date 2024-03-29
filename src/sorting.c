/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:50:45 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/25 01:15:07 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three(t_stacks *s)
{
	t_stack	*a;

	a = s->a;
	if (a->size != 3)
		return ;
	if (a->top == stack_get_max(a))
		sa(s);
	if (a->top->next->n > a->bot->n)
		rra(s);
	if (a->top->n > a->top->next->n)
		sa(s);
}

static void	order_stack(t_stacks *s)
{
	t_frame	*min;

	s->a->mid = ((s->a->size + (s->a->size % 2 != 0)) / 2) - 1;
	min = stack_get_min(s->a);
	while (min->i <= s->a->mid && min->i > 0)
		ra(s);
	while (min->i > s->a->mid && min->i > 0)
		rra(s);
}

void	sort(t_stacks *s)
{
	while (stack_score(s->a) != s->total)
	{
		if (s->a->size == 3)
		{
			sort_three(s);
			get_back_b(s);
		}
		else
			push_non_sorted(s);
	}
	order_stack(s);
}
