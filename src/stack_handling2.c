/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:04:56 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/29 10:07:32 by bazaluga         ###   ########.fr       */
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
