/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:32:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/08 13:11:33 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* void	display_stacks(t_stacks *s) */
/* { */
/* 	t_frame	*a; */
/* 	t_frame	*b; */
/* 	int		i; */

/* 	a = s->a->top; */
/* 	b = s->b->top; */
/* 	i = 0; */
/* 	if (s->a) */
/* 		i = s->a->size; */
/* 	if (s->b && s->b->size > i) */
/* 		i = s->b->size; */
/* 	write(1, "\n\n", 2); */
/* 	while ((a || b) && i >= 0) */
/* 	{ */
/* 		if (a && s->a->size - i >= 0) */
/* 		{ */
/* 			ft_printf("%-2d", a->n); */
/* 			a = a->next; */
/* 		} */
/* 		if (b && s->b->size - i >= 0) */
/* 		{ */
/* 			ft_printf(" %-2d", b->n); */
/* 			b = b->next; */
/* 		} */
/* 		write(1, "\n", 1); */
/* 		i--; */
/* 	} */
/* 	ft_printf("_   _\na   b\n\n\n"); */
/* } */

/* int	tests() */
/* { */
/* 	t_stacks	s; */

/* 	s = stacks_new(); */

/* 	if (!stacks_add_a(&s, 2)) */
/* 		return (stacks_clear(&s), -1); */
/* 	if (!stacks_add_a(&s, 4)) */
/* 		return (stacks_clear(&s), -1); */
/* 	if (!stacks_add_a(&s, 6)) */
/* 		return (stacks_clear(&s), -1); */
/* 	if (!stacks_add_a(&s, 8)) */
/* 		return (stacks_clear(&s), -1); */
/* 	if (!stacks_add_a(&s, 10)) */
/* 		return (stacks_clear(&s), -1); */
/* 	if (!stacks_add_a(&s, 12)) */
/* 		return (stacks_clear(&s), -1); */
/* 	display_stacks(&s); */

/* 	pb(&s); */
/* 	ft_printf("pb\n"); */
/* 	display_stacks(&s); */

/* 	pb(&s); */
/* 	ft_printf("pb\n"); */
/* 	display_stacks(&s); */

/* 	pb(&s); */
/* 	ft_printf("pb\n"); */
/* 	display_stacks(&s); */

/* 	sa(&s); */
/* 	ft_printf("sa\n"); */
/* 	display_stacks(&s); */

/* 	sb(&s); */
/* 	ft_printf("sb\n"); */
/* 	display_stacks(&s); */

/* 	ss(&s); */
/* 	ft_printf("ss\n"); */
/* 	display_stacks(&s); */

/* 	ra(&s); */
/* 	ft_printf("ra\n"); */
/* 	display_stacks(&s); */

/* 	rb(&s); */
/* 	ft_printf("rb\n"); */
/* 	display_stacks(&s); */

/* 	rr(&s); */
/* 	ft_printf("rr\n"); */
/* 	display_stacks(&s); */

/* 	rra(&s); */
/* 	ft_printf("rra\n"); */
/* 	display_stacks(&s); */

/* 	rrb(&s); */
/* 	ft_printf("rrb\n"); */
/* 	display_stacks(&s); */

/* 	rrr(&s); */
/* 	ft_printf("rrr\n"); */
/* 	display_stacks(&s); */

/* 	pa(&s); */
/* 	ft_printf("pa\n"); */
/* 	display_stacks(&s); */

/* 	pa(&s); */
/* 	ft_printf("pa\n"); */
/* 	display_stacks(&s); */

/* 	pa(&s); */
/* 	ft_printf("pa\n"); */
/* 	display_stacks(&s); */
/* 	return (0); */
/* } */

/* void	tests_sort(t_stacks *s) */
/* { */
/* 	char	*n1; */
/* 	char	*n2; */
/* 	int		i1; */
/* 	int		i2; */

/* 	display_stacks(s); */
/* 	n1 = get_next_line(0); */
/* 	n2 = get_next_line(0); */
/* 	i1 = ft_atoi(n1); */
/* 	i2 = ft_atoi(n2); */
/* 	free(n1); */
/* 	free(n2); */
/* 	ft_printf("swap %d & %d\n", i1, i2); */

/* 	display_stacks(s); */
/* } */

int	main(int ac, char *av[])
{
	t_stacks	s;

	if (ac < 2)
		return (1);
	s = stacks_new();
	if (!parse_push_swap(ac, av, &s))
		return (finish_error(&s));
	/* tests_sort(&s); */
	/* display_stacks(&s); */
	stacks_clear(&s);
	/* (void)ac; */
	/* (void)av; */
	/* tests(); */
	return (0);
}
