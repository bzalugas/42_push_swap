/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/12 15:19:45 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stacks	stacks_new(void)
{
	t_stacks	stacks;

	stacks.a = stack_new();
	stacks.b = stack_new();
	stacks.total = 0;
	stacks.cmds = NULL;
	return (stacks);
}

int	stacks_add_a(t_stacks *stacks, int n)
{
	if (!stack_add_back(stacks->a, n))
		return (0);
	stacks->total++;
	return (1);
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
	ft_cmdclear(&stacks->cmds, NULL);
	return (NULL);
}

void	get_a_target(t_stacks *s, t_frame *f)
{
	t_frame	*a;
	t_frame	*min;

	if (f->n > stack_get_max(s->a)->n)
	{
		f->target = stack_get_min(s->a);
		return ;
	}
	a = s->a->top;
	min = a;
	while (a->next)
	{
		a = a->next;
		if (a->n > f->n && a->n < min->n)
			min = a;
	}
	if (min->n < f->n)
		min = stack_get_min(s->a);
	f->target = min;
}

void	get_b_target(t_stacks *s, t_frame *f)
{
	t_frame	*b;
	t_frame	*max;

	if (f->n < stack_get_min(s->b)->n)
	{
		f->target = stack_get_max(s->b);
		return ;
	}
	b = s->b->top;
	max = b;
	while (b->next)
	{
		b = b->next;
		if (b->n < f->n && b->n > max->n)
			max = b;
	}
	if (max->n > f->n)
		max = stack_get_max(s->a);
	f->target = max;
}
