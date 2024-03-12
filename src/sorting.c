/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:50:45 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/12 13:58:01 by bazaluga         ###   ########.fr       */
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

void	push_non_sorted(t_stacks *s)
{

}

void	stacks_sort(t_stacks *s)
{
	if (stack_score(s->a) == s->a->size)
		return ;
	while (stack_score(s->a) < s->total)
	{

	}
}
