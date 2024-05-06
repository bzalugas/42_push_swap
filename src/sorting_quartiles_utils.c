/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_quartiles_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:27:17 by bazaluga          #+#    #+#             */
/*   Updated: 2024/05/06 23:02:47 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_quartile(t_stacks *s, int quart)
{
	t_frame	*cheapest;
	int		cost;
	int		min_cost;
	t_frame	*top;

	min_cost = 0;
	cheapest = NULL;
	top = s->a->top;
	while (top && s->a->size > 3 && (min_cost == 0 || min_cost > 1))
	{
		if (top->quart == quart)
		{
			top->target = s->b->top;
			cost = cost_push(s->a, s->b, top, false);
			if (min_cost == 0 || cost < min_cost)
			{
				min_cost = cost;
				cheapest = top;
			}
		}
		top = top->next;
	}
	if (!cheapest)
		return (0);
	return (push_frame(s, s->a, s->b, cheapest), 1);
}

static int	get_back_quartile(t_stacks *s, int quart)
{
	t_frame	*cheapest;
	int		cost;
	int		min_cost;
	t_frame	*top;

	min_cost = 0;
	cheapest = NULL;
	top = s->b->top;
	while (top && min_cost != 1)
	{
		if (top->quart == quart)
		{
			top->target = get_a_target(s->a, top, true);
			cost = cost_push(s->b, s->a, top, true);
			if (min_cost == 0 || cost < min_cost)
			{
				min_cost = cost;
				cheapest = top;
			}
		}
		top = top->next;
	}
	if (!cheapest)
		return (0);
	return (push_frame(s, s->b, s->a, cheapest), 1);
}

void	get_back_quartiles(t_stacks *s)
{
	int	quart;

	if (s->total < 300)
		quart = 2;
	else
		quart = 4;
	while (quart > 0)
	{
		if (!get_back_quartile(s, quart))
			quart--;
	}
}
