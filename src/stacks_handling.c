/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:05:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/04/30 14:53:34 by bazaluga         ###   ########.fr       */
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

void	stacks_quartiles(t_stacks *s)
{
	int		i;
	int		j;
	t_frame	*tmp;

	get_all_real_targets(s);
	tmp = stack_get_min(s->a);
	s->quartiles[0] = tmp;
	i = 0;
	j = 1;
	while (i < s->total)
	{
		tmp->quart = j;
		if (i == s->a->mid / 2 || i == s->a->mid
			|| i == ((3 * s->total) / 4) || i == s->total - 1)
			s->quartiles[j++] = tmp;
		tmp = tmp->target;
		i++;
	}
}
