/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:31:34 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/29 10:07:42 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_frame	*frame_new(int n, int i, t_frame *next)
{
	t_frame	*new;

	new = (t_frame *)ft_calloc(1, sizeof(t_frame));
	if (!new)
		return (NULL);
	*new = (t_frame) {n, i, next};
	return (new);
}

t_stack	*stack_new()
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	return (new);
}

int	stack_add_back(t_stack *stack, int n)
{
	t_frame	*new;
	int		i;

	i = 0;
	if (stack->top)
		i = stack->top->i + 1;
	new = frame_new(n, i, NULL);
	stack->size++;
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
	t_frame	*top;

	top = stack->top;
	while (top && top->i != i)
		top = top->next;
	return (top);
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
