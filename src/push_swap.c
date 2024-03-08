/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:32:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/08 17:18:34 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



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
