/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:22:44 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/11 13:19:22 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void (*get_fun_single(t_op op))(t_stack *s)
{
	static void (*funs[3])(t_stack *) = {&swap, &rotate, &rrotate};

	if (op < 0 || op > 2)
		return (NULL);
	return (funs[op]);
}
