/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_forward.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:48:49 by bazaluga          #+#    #+#             */
/*   Updated: 2024/02/28 15:54:23 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol_forward(const char *nptr, int *i)
{
	long	n;
	int		sign;

	*i = 0;
	while (nptr[*i] && ft_isspace(nptr[*i]))
		(*i)++;
	sign = 1;
	if (nptr[*i] && (nptr[*i] == '-' || nptr[*i] == '+'))
	{
		if (nptr[*i] == '-')
			sign = -1;
		(*i)++;
	}
	n = 0;
	while (nptr[*i] && ft_isdigit(nptr[*i]))
	{
		n = n * 10 + (nptr[*i] - '0');
		(*i)++;
	}
	return (n * sign);
}
