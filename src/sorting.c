/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:50:45 by bazaluga          #+#    #+#             */
/*   Updated: 2024/05/07 00:03:13 by bazaluga         ###   ########.fr       */
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

void	sort_big(t_stacks *s)
{
	int	quartile;

	quartile = 1;
	stacks_quartiles(s);
	while (stack_score(s->a) != s->a->size)
	{
		if (s->a->size == 3)
		{
			sort_three(s);
			get_back_quartiles(s);
		}
		else
		{
			if (quartile < 5 && !push_quartile(s, quartile))
				quartile++;
		}
	}
	if (s->b->size > 0)
		get_back_quartiles(s);
	order_stack(s);
}

void	sort(t_stacks *s)
{
	if (s->total >= 200)
	{
		sort_big(s);
		return ;
	}
	while (stack_score(s->a) != s->a->size)
	{
		if (s->a->size == 3)
		{
			sort_three(s);
			get_back_b(s);
		}
		else
			push_non_sorted(s);
	}
	if (s->b->size > 0)
		get_back_b(s);
	order_stack(s);
}
