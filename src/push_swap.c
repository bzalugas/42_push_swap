/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:32:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/22 15:47:10 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	test_cost_b(t_stacks *s);
void	test_get_b_target(t_stacks *s);
void	test_push_non_sorted(t_stacks *s);

static char	*op_to_text(void *content)
{
	t_op	op;

	op = (unsigned long)content;
	if (op == SA)
		return ("sa");
	if (op == SB)
		return ("sb");
	if (op == SS)
		return ("ss");
	if (op == PA)
		return ("pa");
	if (op == PB)
		return ("pb");
	if (op == RA)
		return ("ra");
	if (op == RB)
		return ("rb");
	if (op == RR)
		return ("rr");
	if (op == RRA)
		return ("rra");
	if (op == RRB)
		return ("rrb");
	if (op == RRR)
		return ("rrr");
	return (NULL);
}

static void	display_cmds(t_stacks *s)
{
	t_list	*cmd;

	cmd = s->cmds;
	while (cmd)
	{
		ft_putendl_fd(op_to_text(cmd->content), 1);
		cmd = cmd->next;
	}
}

static void	optimize_cmds(t_stacks *s)
{
	t_list	*cmd;
	t_list	*last_rotate;
	t_list	*last_rrotate;

	last_rotate = NULL;
	last_rrotate = NULL;
	cmd = s->cmds;
	while (cmd)
	{
		if (cmd->content == (void*)RA || cmd->content == (void*)RB)
		{
			if (!last_rotate)
				last_rotate = cmd;
			else if (last_rotate && cmd->content != last_rotate->content)
			{
				last_rotate->content = (void*)RR;
				ft_lstremove(&s->cmds, cmd, NULL);
				cmd = last_rotate;
				last_rotate = NULL;
			}
		}
		if (cmd->content == (void*)RRA || cmd->content == (void*)RRB)
		{
			if (!last_rrotate)
				last_rotate = cmd;
			else if (last_rrotate && cmd->content != last_rrotate->content)
			{
				last_rrotate->content = (void*)RR;
				ft_lstremove(&s->cmds, cmd, NULL);
				cmd = last_rrotate;
				last_rrotate = NULL;
			}
		}
		cmd = cmd->next;
	}
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
	optimize_cmds(&s);
	display_cmds(&s);
	//optimize commands
	//display commands
	stacks_clear(&s);
	return (0);
}
