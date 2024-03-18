/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:50:45 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/18 13:26:23 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_three(t_stacks *s)
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

int	cost_push_b(t_stacks *s, t_frame *f, t_frame *t)
{
	int	cost;
	int	mid_a;
	int	mid_b;
	int	cost_a;
	int	cost_b;

	mid_a = ((s->a->size + (s->a->size % 2 != 0)) / 2) - 1;
	mid_b = ((s->b->size + (s->b->size % 2 != 0)) / 2) - 1;
	if (f->i <= mid_a)
		cost_a = f->i;
	else
		cost_a = s->a->size - f->i;
	if (!t)
		return (cost_a + 1);
	if (t->i <= mid_b)
		cost_b = t->i;
	else
		cost_b = s->b->size - t->i;
	if ((f->i <= mid_a && t->i <= mid_b) || (f->i > mid_a && t->i > mid_b))
		cost = ft_max_int(cost_a, cost_b);
	else
		cost = ft_max_int(s->a->size - f->i, s->b->size - t->i);
	cost = ft_min_int(cost_a + cost_b, cost);
	return (cost + 1);
}

/* void	push_non_sorted(t_stacks *s) */
/* { */
/* 	t_frame	*cheapest; */
/* 	int		min_cost; */
/* 	int		cost; */
/* 	int		i; */

/* 	//get all targets in frames */
/* 	//get min_cost */
/* } */

/* void	stacks_sort(t_stacks *s) */
/* { */
/* 	if (stack_score(s->a) == s->a->size) */
/* 		return ; */
/* 	while (s->a->size > 3 && stack_score(s->a) < s->total) */
/* 	{ */

/* 	} */
/* } */

/*
** find 2 non sorted nbs. push the one that costs less to b.
*/
