/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:04:04 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/11 16:13:42 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_cmds	*cmds_new(t_op op)
{
	t_cmds	*new;

	new = (t_cmds *)malloc(sizeof(t_cmds));
	if (!new)
		return (NULL);
	*new = (t_cmds) {op, NULL};
	return (new);
}

int	cmdsadd_back(t_cmds **lst, t_op op)
{
	t_list	*tmp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new || !lst)
		return (0);
	*new = (t_list) {content, NULL};
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	tmp = *lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}
