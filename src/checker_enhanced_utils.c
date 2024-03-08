/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_enhanced_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:49:56 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/08 13:23:26 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_enhanced.h"

static int	get_power(unsigned int n)
{
	if (n < 9)
		return (1);
	return (1 + get_power(n / 10));
}

static int	get_max_pow(int min, int max)
{
	int	powmin;
	int	powmax;

	powmin = get_power(ft_abs(min));
	powmax = get_power(ft_abs(max));
	if (powmin > powmax)
		return (powmin + (min < 0));
	return (powmax + (max < 0));
}

int	get_maxlen(t_stacks *s)
{
	t_frame	*top;
	int		max;
	int		min;

	top = s->a->top;
	max = 0;
	min = 0;
	while (top)
	{
		if (top->n > max)
			max = top->n;
		if (top->n < min)
			min = top->n;
		top = top->next;
	}
	top = s->b->top;
	while (top)
	{
		if (top->n > max)
			max = top->n;
		if (top->n < min)
			min = top->n;
		top = top->next;
	}
	return (get_max_pow(min, max));
}

static void	write_spaces(int len)
{
	int	i;

	i = -1;
	while (++i < len)
		ft_putchar_fd('_', 1);
	ft_putstr_fd("   ", 1);
	i = -1;
	while (++i < len)
		ft_putchar_fd('_', 1);
}

void	write_stacks(t_stacks *s, int len, int i)
{
	t_frame	*a;
	t_frame	*b;

	a = s->a->top;
	b = s->b->top;
	write(1, "\n\n", 2);
	while ((a || b) && i >= 0)
	{
		if (a && s->a->size - i >= 0)
		{
			ft_printf("%-*d", len, a->n);
			a = a->next;
		}
		if (b && s->b->size - i >= 0)
		{
			ft_printf("   %*d", len + ((s->a->size - i < 0) * len), b->n);
			b = b->next;
		}
		write(1, "\n", 1);
		i--;
	}
	write_spaces(len);
	ft_putendl_fd("\n", 1);
}
