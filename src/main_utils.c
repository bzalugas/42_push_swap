/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:28:33 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/08 19:40:43 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	finish_error(t_stacks *s)
{
	stacks_clear(s);
	ft_putendl_fd("Error", 2);
	return (1);
}

static int	parse_one(char *arg, t_stacks *s)
{
	int		i;
	int		tmp;
	long	n;

	if (!arg[0])
		return (0);
	i = 0;
	while (arg[i])
	{
		n = ft_atol_forward(&arg[i], &tmp);
		if (n > INT_MAX || n < INT_MIN || tmp == -1 || stack_get_n(s->a, n))
			return (0);
		stacks_add_a(s, (int)n);
		i += tmp;
		while (ft_isspace(arg[i]))
			i++;
	}
	return (1);
}

static int	parse_multiple(char *av[], t_stacks *s)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!parse_one(av[i], s))
			return (0);
		i++;
	}
	return (1);
}

int	parse_push_swap(int ac, char *av[], t_stacks *s)
{
	if (ac > 2 && !parse_multiple(av, s))
		return (0);
	if (ac == 2 && !parse_one(av[1], s))
		return (0);
	return (1);
}
