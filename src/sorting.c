/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:50:45 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/11 10:10:18 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *s)
{
	t_frame	*max;
	t_frame	*top;

	if (s->size < 3)
		return ;
	max = s->top;
	top = s->top->next;
	while (top)
	{
		if (top->n > max->n)
			max = top;
		top = top->next;
	}
	if (s->top == max)
		rotate(s);
	if (s->top->next->n > s->bot->n)
		rrotate(s);
	if (s->top->n > s->top->next->n)
		swap(s);
}

void	sort_five(t_stack *s)
{
	t_frame	*f;

	if (s->size < 4)
		return ;
	while (stack_score(s) < s->size)
	{
		f = s->top;
		while (f->i < (s->size + (s->size % 2 != 0)) / 2)
		{
			if (f->n > f->next->n) //+ use median ?
			{

			}
			f = f->next;
		}
	}
}

void	sort_b(t_stacks *s)
{
	if (s->b->size == 3)
		sort_three(s->b);
	else
	{

	}
}

void	stacks_sort(t_stacks *s)
{
	t_frame	*a;
	t_frame	*b;

	if (stack_score(s->a) == s->a->size)
		return ;
	while (stack_score(s->a) < s->a->size + s->b->size)
	{
		a = s->a->top;
		b = s->b->top;
		if (a && a->next && a->n > a->next->n)
		{
			if (s->b->size >= 3 && stack_score(s->b) < s->b->size)
				sort_b(s);
			pb(s);
		}
	}
}
