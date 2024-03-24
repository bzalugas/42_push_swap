/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 07:08:10 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/25 00:26:44 by bazaluga         ###   ########.fr       */
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
		get_b_target(s->b, top, true);
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
		get_b_target(s->b, top, true);
		cost = cost_push(s->a, s->b, top);
		ft_printf("cost for %d=%d\n", top->n, cost);
		top = top->next;
	}
	rrr(s);
	ft_putendl_fd("\n\n", 1);
	top = s->a->top;
	while (top)
	{
		get_b_target(s->b, top, true);
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
		get_b_target(s->b, top, true);
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
		get_b_target(s->b, top, true);
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
		get_b_target(s->b, top, true);
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
		get_b_target(s->b, top, true);
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
		get_b_target(s->b, top, true);
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

void	test_optimize(void)
{
	t_list	*cmds;

	cmds = NULL;
	ft_cmdadd_back(&cmds, PB);
	ft_cmdadd_back(&cmds, PB);
	ft_cmdadd_back(&cmds, RA);
	ft_cmdadd_back(&cmds, RA);
	ft_cmdadd_back(&cmds, RB);
	ft_cmdadd_back(&cmds, RB);
	ft_cmdadd_back(&cmds, PB);
	ft_cmdadd_back(&cmds, PB);
	ft_cmdadd_back(&cmds, RA);
	ft_cmdadd_back(&cmds, RA);
	ft_cmdadd_back(&cmds, PB);
	ft_cmdadd_back(&cmds, RB);
	ft_cmdadd_back(&cmds, RB);
	ft_cmdadd_back(&cmds, PA);
	ft_cmdadd_back(&cmds, RA);
	ft_cmdadd_back(&cmds, RB);
	ft_cmdadd_back(&cmds, RA);
	ft_cmdadd_back(&cmds, SA);
	ft_cmdadd_back(&cmds, RB);
	display_cmds(cmds);
	ft_putendl_fd("\n", 1);
	optimize_cmds(cmds);
	display_cmds(cmds);
}

void	test_real_target(t_stacks *s)
{
	t_frame	*top;

	top = s->a->top;
	while (top)
	{
		get_real_target(s, top, true);
		ft_printf("real target of %d is %d\n", top->n, top->target->n);
		top = top->next;
	}
	pb(s);
	pb(s);
	pb(s);
	display_cmds(s->cmds);
	top = s->a->top;
	while (top)
	{
		get_real_target(s, top, true);
		ft_printf("real target of %d is %d\n", top->n, top->target->n);
		top = top->next;
	}
}

/* void	test_sorted(t_stacks *s) */
/* { */
/* 	t_frame	*top; */
/* 	bool	is_sorted; */

/* 	top = s->a->top; */
/* 	while (top) */
/* 	{ */
/* 		get_real_target(s, top, true); */
/* 		is_sorted = sorted(s, s->a, top); */
/* 		ft_printf("%d is %s\n", top->n, is_sorted ? "sorted." : "not sorted."); */
/* 		top = top->next; */
/* 	} */
/* 	pb(s); */
/* 	pb(s); */
/* 	pb(s); */
/* 	rra(s); */
/* 	rra(s); */
/* 	display_cmds(s->cmds); */
/* 	top = s->a->top; */
/* 	while (top) */
/* 	{ */
/* 		get_real_target(s, top, true); */
/* 		is_sorted = sorted(s, s->a, top); */
/* 		ft_printf("%d is %s\n", top->n, is_sorted ? "sorted." : "not sorted."); */
/* 		top = top->next; */
/* 	} */
/* } */

void	test_get_median(t_stacks *s)
{
	stacks_get_median(s);
	ft_printf("median is %d\n", s->med);
}
