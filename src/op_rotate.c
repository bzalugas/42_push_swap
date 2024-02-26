/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:16:59 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/26 19:07:04 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_frame **top, t_frame **bottom)
{
	t_frame	*tmp;

	if (!*top)
		return ;
	if (!(*top)->next)
		return ;
	tmp = (*top)->next;
	(*bottom)->next = *top;
	(*top)->next = NULL;
	*bottom = *top;
	*top = tmp;
	stack_update_indexes(*top, (*bottom)->i);
}

void	rr(t_frame **a, t_frame **bot_a, t_frame **b, t_frame **bot_b)
{
	rotate(a, bot_a);
	rotate(b, bot_b);
}

void	rrotate(t_frame **top, t_frame **bottom)
{
	if (!*top || !*bottom)
		return ;
	(*bottom)->next = *top;
	*top = *bottom;
	*bottom = stack_get_index(*top, 1);
	(*bottom)->next = NULL;
	stack_update_indexes(*top, (*top)->next->i);
}

void	rrr(t_frame **a, t_frame **bot_a, t_frame **b, t_frame **bot_b)
{
	rrotate(a, bot_a);
	rrotate(b, bot_b);
}
