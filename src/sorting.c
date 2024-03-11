/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:50:45 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/11 16:03:25 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_op	*get_stack_cmds(t_stacks *s, t_stack *stack)
{
	static t_op	cmd_a[3] = {SA, RA, RRA};
	static t_op	cmd_b[3] = {SB, RB, RRB};

	if (stack == s->a)
		return (cmd_a);
	return (cmd_b);
}

t_list *sort_three(t_stacks *ss, t_stack *s)
{
	t_list	*tmp;
	t_op	*cmds;

	cmds = get_stack_cmds(ss, s);
	tmp = ft_lstlast(ss->cmd);
	if (s->size < 3)
		return (NULL);
	if (s->top == stack_get_max(s) && ft_lstadd_back2(&ss->cmd, (void *)cmds[2]))
		rotate(s);
	if (s->top->next->n > s->bot->n && ft_lstadd_back2(&ss->cmd, (void *)RRO))
		rrotate(s);
	if (s->top->n > s->top->next->n && ft_lstadd_back2(&ss->cmd, (void *)S))
		swap(s);
	return (tmp->next);
}

void	sort_five(t_stack *s)
{
	t_frame	*f;

	if (s->size < 4 || s->size > 5)
		return ;
	while (stack_score(s) < s->size)
	{
		f = s->top;
		while (f->i < (s->size + (s->size % 2 != 0)) / 2)
		{
			if (f->n > f->next->n) //+ use median ?
			{
				if (f == stack_get_max(s))
					rotate(s);
			}
			f = f->next;
		}
	}
}

void	sort_b(t_stacks *s)
{
	if (s->b->size == 3)
		sort_three(s->b);
	else
	{

	}
}

void	stacks_sort(t_stacks *s)
{
	t_frame	*a;
	t_frame	*b;

	if (stack_score(s->a) == s->a->size)
		return ;
	while (stack_score(s->a) < s->a->size + s->b->size)
	{
		a = s->a->top;
		b = s->b->top;
		if (a && a->next && a->n > a->next->n)
		{
			if (s->b->size >= 3 && stack_score(s->b) < s->b->size)
				sort_b(s);
			pb(s);
		}
	}
}
