/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:32:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/27 14:41:35 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_stacks(t_stacks *s)
{
	int	i;
	t_frame	*a;
	t_frame	*b;

	a = s->a->top;
	b = s->b->top;
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
	t_stacks	s;

	s = stacks_new();

	if (!stacks_add_a(&s, 2))
		return (stacks_clear(&s), -1);
	if (!stacks_add_a(&s, 4))
		return (stacks_clear(&s), -1);
	if (!stacks_add_a(&s, 6))
		return (stacks_clear(&s), -1);
	if (!stacks_add_a(&s, 8))
		return (stacks_clear(&s), -1);
	if (!stacks_add_a(&s, 10))
		return (stacks_clear(&s), -1);
	if (!stacks_add_a(&s, 12))
		return (stacks_clear(&s), -1);
	display_stacks(&s);

	pb(&s);
	display_stacks(&s);

	pb(&s);
	display_stacks(&s);

	pb(&s);
	display_stacks(&s);

	sa(&s);
	display_stacks(&s);

	sb(&s);
	display_stacks(&s);

	ss(&s);
	display_stacks(&s);

	ra(&s);//problem rotate
	display_stacks(&s);

	rb(&s);
	display_stacks(&s);

	rr(&s);
	display_stacks(&s);

	rra(&s);
	display_stacks(&s);

	rrb(&s);
	display_stacks(&s);

	rrr(&s);
	display_stacks(&s);

	return (0);
}
