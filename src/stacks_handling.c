/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/08 19:53:25 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stacks	stacks_new(void)
{
	t_stacks	stacks;

	stacks.a = stack_new();
	stacks.b = stack_new();
	return (stacks);
}

int	stacks_add_a(t_stacks *stacks, int n)
{
	return (stack_add_back(stacks->a, n));
}

void	*stacks_clear(t_stacks *stacks)
{
	t_frame	*tmp;
	t_frame	*a;
	t_frame	*b;

	a = stacks->a->top;
	b = stacks->b->top;
	while (a || b)
	{
		if (a)
		{
			tmp = a->next;
			free(a);
			a = tmp;
		}
		if (b)
		{
			tmp = b->next;
			free(b);
			b = tmp;
		}
	}
	free(stacks->a);
	free(stacks->b);
	*stacks = (t_stacks){0, 0};
	return (NULL);
}

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
