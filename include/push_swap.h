/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:31:57 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/26 18:05:20 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_frame
{
	int				n;
	int				i;
	struct s_frame	*next;
}				t_frame;

int		stack_add(t_frame **top, t_frame **bottom, int n);
void	*stacks_clear(t_frame *a, t_frame *b);
void	stack_update_indexes(t_frame *stack, int max);
t_frame	*stack_get_index(t_frame *top, int i);

/********************************* OPERATIONS *********************************/

void	swap(t_frame **top);
void	ss(t_frame **a, t_frame **b);

void	push(t_frame **from, t_frame **to);

void	rotate(t_frame **top, t_frame **bottom);
void	rr(t_frame **a, t_frame **bot_a, t_frame **b, t_frame **bot_b);

void	rrotate(t_frame **top, t_frame **bottom);
void	rrr(t_frame **a, t_frame **bot_a, t_frame **b, t_frame **bot_b);

#endif
