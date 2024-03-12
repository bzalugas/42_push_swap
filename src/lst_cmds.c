/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:02:52 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/12 14:02:56 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_cmdadd_back(t_list **lst, t_op op)
{
	t_list	*tmp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new || !lst)
		return (0);
	*new = (t_list) {(void *)op, NULL};
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

void	ft_cmdclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
