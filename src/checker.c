/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:52:48 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/05 20:29:43 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	finish_error(t_stacks *s)
{
	stacks_clear(s);
	ft_putendl_fd("Error", 2);
	return (1);
}

static int	parse(int ac, char *av[], t_stacks *s)
{
	int		i;
	int		j;
	long	n;
	int		tmp;

	i = 1;
	j = 0;
	while (av[i] && av[i][j])
	{
		n = ft_atol_forward(&av[i][j], &tmp);
		if (n > INT_MAX || n < INT_MIN || tmp == -1 || stack_get_n(s->a, n))
			return (0);
		stacks_add_a(s, (int)n);
		j += tmp;
		if (ac > 2)
		{
			if (av[i][j] != '\0')
				return (0);
			i++;
			j = 0;
		}
	}
	if (ac > 2 && i < ac)
		return (0);
	return (1);
}

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

static int do_fun(t_stacks *s, char *content)
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
	t_stack	*a;

	a = s->a;
	if (ok)
	{
		while ()
		{

		}
	}
	if (!ok)
	{
		ft_lstclear(&op, &free);
		stacks_clear(s);
		ft_putendl_fd("KO", 1);
		return (1);
	}
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
	ft_lstclear(&op, &free);
	stacks_clear(&s);
	return (0);
}
