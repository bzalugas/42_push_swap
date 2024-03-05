/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:53:52 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/05 11:34:43 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void int_swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

static void	swap_adj_els(t_stacks *s, t_frame *f1)
{
	int		count;
	char	op;

	count = 0;
	op = 1;
	if (f1->i >= s->a->size / 2)
		op = 2;
	while (f1->i > 0) //&& ++count
	{
		if (op == 1)
			ra(s);
		else
			rra(s);
		count++;
	}
	sa(s);
	while (count > 0)
	{
		if (op == 1)
			rra(s);
		else
			ra(s);
		count--;
	}
}

static void	pushb_el(t_stacks *s, t_frame *f1)
{
	char	op;

	op = 1;
	if (f1->i >= s->a->size / 2)
		op = 2;
}

static void	swap_els(t_stacks *s, t_frame *f1, t_frame *f2)
{

}

void	stack_swap_els(t_stacks *s, int i1, int i2)
{
	if (i1 > i2)
		int_swap(&i1, &i2);
	if (i1 + 1 == i2 || i2 + 1 == i1)
		swap_adj_els(s, stack_get_i(s->a, i1));
}
