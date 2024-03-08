/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:04:56 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/08 17:51:33 by bazaluga         ###   ########.fr       */
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
	t_frame	*top;

	score = 0;
	top = s->top;
	while (top && top != s->bot)
	{
		if (!top->next || (top->next && (top->next->n > top->n)))
			score++;
		top = top->next;
	}
	return (score);
}
