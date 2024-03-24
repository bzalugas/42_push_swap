/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:50:45 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/24 18:32:56 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stacks *s)
{
	t_stack	*a;

	a = s->a;
	if (a->size < 3)
		return ;
	if (a->top == stack_get_max(a))
		sa(s);
	if (a->top->next->n > a->bot->n)
		rra(s);
	if (a->top->n > a->top->next->n)
		sa(s);
}

void	order_stack(t_stacks *s)
{
	t_frame	*min;
	int		mid_a;//use s->a->mid

	mid_a = ((s->a->size + (s->a->size % 2 != 0)) / 2) - 1;
	min = stack_get_min(s->a);
	while (min->i <= mid_a && min->i > 0)
		ra(s);
	while (min->i > mid_a && min->i > 0)
		rra(s);
}

void	swap_frames_a(t_stacks *s, t_frame *f1)
{
	int	target_i;

	target_i = 0;
	/* if (f1 == stack_get_max(s->a)) */
	/* 	target_i = s->a->size - 1; */
	while (f1->i <= s->a->mid && f1->i != target_i)
		ra(s);
	while (f1->i > s->a->mid && f1->i != target_i)
		rra(s);
	/* if (target_i == 0) */
		sa(s);
}

void	sort_stack(t_stacks *ss, t_stack *s)
{
	t_frame	*top;
	t_frame	*min;
	t_frame	*max;

	if (s->size == 3)
	{
		sort_three(ss);
		return ;
	}
	min = stack_get_min(s);
	max = stack_get_max(s);
	top = s->top;
	while (top)
	{
		if (!top->next && top != max)
			ft_printf("%d is not max.\n", top->n);
		if ((top->next && top->next->n < top->n && top != max
			&& top->next != min) || (!top->next && top != max))
		{
			swap_frames_a(ss, top);
			top = s->top;
		}
		else
			top = top->next;
	}
}

void	sort(t_stacks *s)
{
	stacks_get_median(s);
	while (stack_score(s->a) != s->total)
	{
		if (s->a->size == (s->total + (s->total % 2 != 0)) / 2)
		{
			sort_stack(s, s->a);
			get_back_b(s);
		}
		else
			push_non_sorted(s);

		/* if (s->a->size == 3) */
		/* { */
		/* 	sort_three(s); */
		/* 	get_back_b(s); */
		/* } */
		/* else */
		/* 	push_non_sorted(s); */
	}
	order_stack(s);
}
