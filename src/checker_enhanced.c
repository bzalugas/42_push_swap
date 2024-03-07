/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_enhanced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:00:41 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/07 16:05:33 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_enhanced.h"

static void	display_stacks(t_stacks *s)
{
	int		i;
	int		maxlen;

	ft_putstr_fd("\033[2J", 1);
	ft_putstr_fd("\033[H", 1);
	maxlen = get_maxlen(s);
	i = 0;
	if (s->a)
		i = s->a->size;
	if (s->b && s->b->size > i)
		i = s->b->size;
	write_stacks(s, maxlen, i);
}

static int	do_fun(t_stacks *s, char *content)
{
	if (!ft_strncmp(content, "rra", 3))
		rra(s);
	else if (!ft_strncmp(content, "rrb", 3))
		rrb(s);
	else if (!ft_strncmp(content, "rrr", 3))
		rrr(s);
	else if (!ft_strncmp(content, "sa", 2))
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
	else
		return (0);
	return (1);
}

static int	get_do_ops(t_stacks *s)
{
	char	*line;
	int		count;

	count = 0;
	display_stacks(s);
	line = get_next_line(0);
	while (line)
	{
		count++;
		do_fun(s, line);
		display_stacks(s);
		line = get_next_line(0);
	}
	return (count);
}

static int	result(t_stacks *s, int nb_op, char ok)
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
	stacks_clear(s);
	if (!ok)
		ft_printf("KO (%d operations)\n", nb_op);
	else
		ft_printf("OK (%d operations)\n", nb_op);
	return (0);
}

int	main(int ac, char *av[])
{
	t_stacks	s;
	int			nb_op;

	if (ac < 2)
		return (1);
	s = stacks_new();
	if (!parse(ac, av, &s))
		return (finish_error(&s));
	nb_op = get_do_ops(&s);
	return (result(&s, nb_op, 1));
}
