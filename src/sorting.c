/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:50:45 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/12 15:01:09 by bazaluga         ###   ########.fr       */
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
	int	med_a;
	int	med_b;

	med_a = s->a->size + (s->a->size % 2 != 0) / 2;
	med_b = s->b->size + (s->b->size % 2 != 0) / 2;
	if ((f->i <= med_a && t->i <= med_b) || (f->i > med_a && t->i > med_b))
		cost = ft_max_int(f->i, t->i) - ft_min_int(f->i, t->i);
	else
		cost = f->i + t->i;
	return (cost + 1);
}

void	push_non_sorted(t_stacks *s)
{
	t_frame	*cheapest;
	int		min_cost;


}

void	stacks_sort(t_stacks *s)
{
	if (stack_score(s->a) == s->a->size)
		return ;
	while (s->a->size > 3 && stack_score(s->a) < s->total)
	{

	}
}

/*
** find 2 non sorted nbs. push the one that costs less to b.
*/
