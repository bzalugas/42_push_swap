/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:31:34 by bazaluga          #+#    #+#             */
/*   Updated: 2024/05/06 23:01:46 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_frame	*frame_new(int n, int i, t_frame *prev, t_frame *next)
{
	t_frame	*new;

	new = (t_frame *)ft_calloc(1, sizeof(t_frame));
	if (!new)
		return (NULL);
	*new = (t_frame){n, i, 0, {0, 0}, NULL, prev, next};
	return (new);
}

t_stack	*stack_new(void)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	return (new);
}

int	stack_add_back(t_stack *stack, int n)
{
	t_frame	*new;
	int		i;

	i = stack->size;
	new = frame_new(n, i, stack->bot, NULL);
	if (!new)
		return (0);
	stack->size++;
	stack->mid = ((stack->size + (stack->size % 2 != 0)) / 2) - 1;
	if (!stack->top)
	{
		stack->top = new;
		stack->bot = new;
		return (1);
	}
	stack->bot->next = new;
	stack->bot = new;
	return (1);
}

t_frame	*stack_get_i(t_stack *stack, int i)
{
	t_frame	*f;
	bool	top;

	if (i >= stack->size || i < 0)
		return (NULL);
	top = true;
	if (i > (stack->size + (stack->size % 2 != 0)) / 2)
		top = false;
	if (top)
		f = stack->top;
	else
		f = stack->bot;
	while (f && f->i != i)
	{
		if (top)
			f = f->next;
		else
			f = f->prev;
	}
	return (f);
}

void	stack_update_i(t_stack *stack)
{
	t_frame	*top;
	int		i;

	top = stack->top;
	i = 0;
	while (i < stack->size && top)
	{
		top->i = i;
		top = top->next;
		i++;
	}
}
