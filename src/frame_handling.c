/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:44:47 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/26 18:00:31 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_frame	*frame_new(int n, int i, t_frame *next)
{
	t_frame	*new;

	new = (t_frame *)ft_calloc(1, sizeof(t_frame));
	if (!new)
		return (NULL);
	*new = (t_frame) {n, i, next};
	return (new);
}

int	stack_add(t_frame **top, t_frame **bottom, int n)
{
	t_frame	*new;
	int		i;

	if (!top || !bottom)
		return (0);
	if (!*top)
		i = 0;
	else
		i = (*top)->i + 1;
	new = frame_new(n, i, *top);
	if (!new)
		return (0);
	if (!*bottom)
		*bottom = *top;
	*top = new;
	return (1);
}

void	*stacks_clear(t_frame *a, t_frame *b)
{
	t_frame	*tmp;

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
	return (NULL);
}

void	stack_update_indexes(t_frame *stack, int max)
{
	int	i;

	i = max;
	while (stack && i >= 0)
	{
		stack->i = i--;
		stack = stack->next;
	}
}

t_frame	*stack_get_index(t_frame *top, int i)
{
	while (top && top->i != i)
		top = top->next;
	return (top);
}
