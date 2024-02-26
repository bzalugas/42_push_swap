/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:55:37 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/26 17:49:08 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_frame **from, t_frame **to)
{
	t_frame	*tmp;

	if (!*from)
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	*from = *to;
	*from = tmp;
	if ((*to)->next)
		(*to)->i = (*to)->next->i + 1;
	else
		(*from)->i = 0;
}
