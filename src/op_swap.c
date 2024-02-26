/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:03:53 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/26 17:47:50 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_frame **top)
{
	t_frame	*tmp;
	int		index_top;

	if (!*top || !(*top)->next)
		return ;
	tmp = (*top)->next;
	(*top)->next = (*top)->next->next;
	tmp->next = *top;
	index_top = (*top)->i;
	(*top)->i = tmp->i;
	tmp->i = index_top;
	*top = tmp;
}

void	ss(t_frame **a, t_frame **b)
{
	swap(a);
	swap(b);
}
