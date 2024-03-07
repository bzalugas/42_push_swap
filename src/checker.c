/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:52:48 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/07 13:58:21 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	get_operations(t_list **op)
{
	char	*line;
	t_list	*new;

	line = get_next_line(0);
	while (line)
	{
		new = ft_lstnew(line);
		if (!new)
			return (free(line), 0);
		ft_lstadd_back(op, new);
		line = get_next_line(0);
	}
	return (1);
}

static int	do_fun(t_stacks *s, char *content)
{
	if (!ft_strncmp(content, "sa", 2))
		sa(s);
	else if (!ft_strncmp(content, "sb", 2))
		sb(s);
	else if (!ft_strncmp(content, "ss", 2))
		ss(s);
	else if (!ft_strncmp(content, "pa", 2))
		pa(s);
	else if (!ft_strncmp(content, "pb", 2))
		pb(s);
	else if (!ft_strncmp(content, "ra", 2))
		ra(s);
	else if (!ft_strncmp(content, "rb", 2))
		rb(s);
	else if (!ft_strncmp(content, "rr", 2))
		rr(s);
	else if (!ft_strncmp(content, "rra", 3))
		rra(s);
	else if (!ft_strncmp(content, "rrb", 3))
		rrb(s);
	else if (!ft_strncmp(content, "rrr", 3))
		rrr(s);
	else
		return (0);
	return (1);
}

static int	do_ops(t_stacks *s, t_list *op)
{
	while (op)
	{
		if (!do_fun(s, (char *)op->content))
			return (0);
		op = op->next;
	}
	return (1);
}

static int	result(t_stacks *s, t_list *op, char ok)
{
	t_frame	*a;

	a = s->a->top;
	if (s->b->top)
		ok = 0;
	if (ok)
	{
		while (ok && a && a->next)
		{
			if (a->n > a->next->n)
				ok = 0;
			a = a->next;
		}
	}
	ft_lstclear(&op, &free);
	stacks_clear(s);
	if (!ok)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_stacks	s;
	t_list		*op;

	if (ac < 2)
		return (1);
	s = stacks_new();
	if (!parse(ac, av, &s))
		return (finish_error(&s));
	if (!get_operations(&op))
		return (ft_lstclear(&op, &free), 1);
	if (!do_ops(&s, op))
		return (result(&s, op, 0));
	return (result(&s, op, 1));
}
