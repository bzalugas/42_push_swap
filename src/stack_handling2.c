/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:04:56 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/24 17:15:48 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_frame	*stack_get_n(t_stack *s, int n)
{
	t_frame	*top;

	top = s->top;
	while (top && top->n != n)
		top = top->next;
	return (top);
}

int	stack_score(t_stack *s)
{
	int		score;
	t_frame	*max;
	t_frame	*min;
	t_frame	*top;

	max = stack_get_max(s);
	min = stack_get_min(s);
	score = 0;
	top = s->top;
	while (top)
	{
		if (!top->next || (top->next && (top->next->n > top->n)))
			score++;
		else if (top->next && top == max && top->next == min)
			score++;
		top = top->next;
	}
	return (score);
}

t_frame	*stack_get_max(t_stack *s)
{
	t_frame	*max;
	t_frame	*top;

	max = s->top;
	top = s->top->next;
	while (top)
	{
		if (top->n > max->n)
			max = top;
		top = top->next;
	}
	return (max);
}

t_frame	*stack_get_min(t_stack *s)
{
	t_frame	*min;
	t_frame	*top;

	if (s->size < 2)
		return (s->top);
	min = s->top;
	top = s->top->next;
	while (top)
	{
		if (top->n < min->n)
			min = top;
		top = top->next;
	}
	return (min);
}

void	stack_update_mid(t_stack *s)
{
	s->mid = ((s->size + (s->size % 2 != 0)) / 2) - 1;
}
