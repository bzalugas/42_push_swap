/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:32:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/26 19:03:47 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_stacks(t_frame *a, t_frame *b)
{
	int	i;

	i = -1;
	if (a)
		i = a->i;
	else if (b && b->i > i)
		i = b->i;
	else
		return ;
	write(1, "\n\n", 2);
	while ((a || b) && i >= 0)
	{
		if (a && a->i == i)
		{
			ft_printf("%d", a->n);
			a = a->next;
		}
		if (b && b->i == i)
		{
			ft_printf(" %d", b->n);
			b = b->next;
		}
		write(1, "\n", 1);
		i--;
	}
	write(1, "_ _\na b\n\n\n", 10);
}

int	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	t_frame	*top_a;
	t_frame	*bot_a;
	t_frame	*top_b;
	t_frame	*bot_b;

	top_b = NULL;
	bot_b = NULL;
	if (!stack_add(&top_a, &bot_a, 2))
		return (-1);
	if (!stack_add(&top_a, &bot_a, 4))
		return (-1);
	if (!stack_add(&top_a, &bot_a, 6))
		return (-1);
	if (!stack_add(&top_a, &bot_a, 8))
		return (-1);
	if (!stack_add(&top_a, &bot_a, 10))
		return (-1);
	if (!stack_add(&top_a, &bot_a, 12))
		return (-1);
	display_stacks(top_a, top_b);

	push(&top_a, &top_b);
	display_stacks(top_a, top_b);

	push(&top_a, &top_b);
	push(&top_a, &top_b);
	display_stacks(top_a, top_b);

	swap(&top_a);
	display_stacks(top_a, top_b);

	swap(&top_b);
	display_stacks(top_a, top_b);

	ss(&top_a, &top_b);
	display_stacks(top_a, top_b);

	rotate(&top_a, &bot_a);
	display_stacks(top_a, top_b);

	rotate(&top_b, &bot_b);
	display_stacks(top_a, top_b);

	rr(&top_a, &bot_a, &top_b, &bot_b);
	display_stacks(top_a, top_b);

	rrotate(&top_a, &bot_a);
	display_stacks(top_a, top_b);

	rrotate(&top_b, &bot_b);
	display_stacks(top_a, top_b);

	rrr(&top_a, &bot_a, &top_b, &bot_b);
	display_stacks(top_a, top_b);

	return (0);
}
