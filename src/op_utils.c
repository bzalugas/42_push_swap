/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:22:44 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/22 12:12:26 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void (*get_fun_single(t_op op))(t_stacks *s)
{
	static void (*funs[5])(t_stacks *) = {&ra, &rra, &rb, &rrb, &pb};

	if (op < 0 || op > 2)
		return (NULL);
	return (funs[op]);
}
