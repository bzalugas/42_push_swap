/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:28:33 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/07 13:30:29 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	finish_error(t_stacks *s)
{
	stacks_clear(s);
	ft_putendl_fd("Error", 2);
	return (1);
}

int	parse(int ac, char *av[], t_stacks *s)
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
