/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 07:08:10 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/23 15:30:53 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	test_cost_b(t_stacks *s)
{
	t_frame *top;
	int		cost;
	int		i;

	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		cost = cost_push(s->a, s->b, top);
		ft_printf("cost for %d=%d\n", top->n, cost);
		top = top->next;
	}
	i = (s->a->size / 2) + 1;
	while (--i > 0)
		pb(s);
	ft_putendl_fd("\n\n", 1);
	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		cost = cost_push(s->a, s->b, top);
		ft_printf("cost for %d=%d\n", top->n, cost);
		top = top->next;
	}
	rrr(s);
	ft_putendl_fd("\n\n", 1);
	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		cost = cost_push(s->a, s->b, top);
		ft_printf("cost for %d=%d\n", top->n, cost);
		top = top->next;
	}
}

void	test_get_b_target(t_stacks *s)
{
	t_frame	*top;
	int		i;

	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		if (!top->target)
			ft_printf("No target for %d\n", top->n);
		else
			ft_printf("target of %d is %d\n", top->n, top->target->n);
		top = top->next;
	}
	i = ((s->a->size + (s->a->size % 2 != 0))/ 2) + 1;
	while (--i > 0)
		pb(s);
	ft_putendl_fd("\n\n", 1);
	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		if (!top->target)
			ft_printf("No target for %d\n", top->n);
		else
			ft_printf("target of %d is %d\n", top->n, top->target->n);
		top = top->next;
	}
	rrr(s);
	ft_putendl_fd("\n\n", 1);
	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		if (!top->target)
			ft_printf("No target for %d\n", top->n);
		else
			ft_printf("target of %d is %d\n", top->n, top->target->n);
		top = top->next;
	}
	pb(s);
	ft_putendl_fd("\n\n", 1);
	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		if (!top->target)
			ft_printf("No target for %d\n", top->n);
		else
			ft_printf("target of %d is %d\n", top->n, top->target->n);
		top = top->next;
	}
	rb(s);
	i = s->b->size - 1;
	while (--i > 0)
		pa(s);
	ft_putendl_fd("\n\n", 1);
	top = s->a->top;
	while (top)
	{
		get_b_target(s, top);
		if (!top->target)
			ft_printf("No target for %d\n", top->n);
		else
			ft_printf("target of %d is %d\n", top->n, top->target->n);
		top = top->next;
	}
}

void	test_push_non_sorted(t_stacks *s)
{
	int score;

	score = stack_score(s->a);
	while (score != s->a->size)
	{
		push_non_sorted(s);
		score = stack_score(s->a);
	}

}

/* void	optimize_cmds(t_list *cmds); */
/* void	display_cmds(t_list *cmds); */
/* void	test_optimize() */
/* { */
/* 	t_list	*cmds; */

/* 	cmds = NULL; */
/* 	ft_cmdadd_back(&cmds, PB); */
/* 	ft_cmdadd_back(&cmds, PB); */
/* 	ft_cmdadd_back(&cmds, RA); */
/* 	ft_cmdadd_back(&cmds, RA); */
/* 	ft_cmdadd_back(&cmds, RB); */
/* 	ft_cmdadd_back(&cmds, RB); */
/* 	ft_cmdadd_back(&cmds, PB); */
/* 	ft_cmdadd_back(&cmds, PB); */
/* 	ft_cmdadd_back(&cmds, RA); */
/* 	ft_cmdadd_back(&cmds, RA); */
/* 	ft_cmdadd_back(&cmds, PB); */
/* 	ft_cmdadd_back(&cmds, RB); */
/* 	ft_cmdadd_back(&cmds, RB); */
/* 	ft_cmdadd_back(&cmds, PA); */
/* 	ft_cmdadd_back(&cmds, RA); */
/* 	ft_cmdadd_back(&cmds, RB); */
/* 	ft_cmdadd_back(&cmds, RA); */
/* 	ft_cmdadd_back(&cmds, SA); */
/* 	ft_cmdadd_back(&cmds, RB); */
/* 	display_cmds(cmds); */
/* 	ft_putendl_fd("\n", 1); */
/* 	optimize_cmds(cmds); */
/* 	display_cmds(cmds); */
/* } */
