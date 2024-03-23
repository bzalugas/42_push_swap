/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:32:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/23 16:50:42 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	test_cost_b(t_stacks *s);
void	test_get_b_target(t_stacks *s);
void	test_push_non_sorted(t_stacks *s);
void	test_optimize(void);

void	display_cmds(t_list *cmds)
{
	while (cmds)
	{
		ft_putendl_fd(op_to_text(cmds->content), 1);
		cmds = cmds->next;
	}
}

static void	optimize_rotate(t_list *cmds)
{
	t_list	*cmd;
	t_list	*last;

	last = NULL;
	cmd = cmds;
	while (cmd)
	{
		if (last && (cmd->content == (void *)PB || cmd->content == (void *)PA))
			last = NULL;
		if (cmd->content == (void *)RA || cmd->content == (void *)RB)
		{
			if (!last)
				last = cmd;
			else if (last && cmd->content != last->content)
			{
				last->content = (void *)RR;
				ft_lstremove(&cmds, cmd, NULL);
				cmd = last;
				last = NULL;
			}
		}
		cmd = cmd->next;
	}
}

static void	optimize_rrotate(t_list *cmds)
{
	t_list	*cmd;
	t_list	*last;

	last = NULL;
	cmd = cmds;
	while (cmd)
	{
		if (last && (cmd->content == (void *)PB || cmd->content == (void *)PA))
			last = NULL;
		if (cmd->content == (void *)RRA || cmd->content == (void *)RRB)
		{
			if (!last)
				last = cmd;
			else if (last && cmd->content != last->content)
			{
				last->content = (void *)RRR;
				ft_lstremove(&cmds, cmd, NULL);
				cmd = last;
				last = NULL;
			}
		}
		cmd = cmd->next;
	}
}

void	optimize_cmds(t_list *cmds)
{
	optimize_rotate(cmds);
	optimize_rrotate(cmds);
}

int	main(int ac, char *av[])
{
	t_stacks	s;

	if (ac < 2)
		return (1);
	s = stacks_new();
	if (!parse_push_swap(ac, av, &s))
		return (finish_error(&s));
	sort(&s);
	optimize_cmds(s.cmds);
	display_cmds(s.cmds);
	stacks_clear(&s);
	return (0);
}
