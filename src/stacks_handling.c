/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/25 00:28:37 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stacks	stacks_new(void)
{
	t_stacks	stacks;

	stacks.a = stack_new();
	stacks.b = stack_new();
	stacks.total = 0;
	stacks.med = 0;
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

void	stacks_get_median(t_stacks *s)
{
	t_frame	*last;
	int		mid_a;

	mid_a = ((s->a->size + (s->a->size % 2 != 0)) / 2) - 1;
	last = stack_get_min(s->a);
	while (mid_a > 0)
	{
		get_real_target(s, last, true);
		last = last->target;
		mid_a--;
	}
	s->med = last->n;
}
