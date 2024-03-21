/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazaluga <bazaluga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:32:07 by bazaluga          #+#    #+#             */
/*   Updated: 2024/03/21 15:29:59 by bazaluga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	test_cost_b(t_stacks *s);
void	test_get_b_target(t_stacks *s);
void	test_push_non_sorted(t_stacks *s);

static char	*op_to_text(void *content)
{
	t_op	op;

	op = (t_op)content;
	if (content == SA)
		return ("sa");
	if (content == SB)
		return ("sb");
	if (content == SS)
		return ("ss");
	if (content == PA)
		return ("pa");
	if (content == PB)
		return ("pb");
	if (content == RA)
		return ("ra");
	if (content == RB)
		return ("rb");
	if (content == RR)
		return ("rr");
	if (content == RRA)
		return ("rra");
	if (content == RRB)
		return ("rrb");
	if (content == RRR)
		return ("rrr");
}

static void	display_cmds(t_stacks *s)
{
	t_list	*cmd;

	cmd = s->cmds;
	ft_putendl_fd(op_to_text(cmd->content), 1);
}

int	main(int ac, char *av[])
{
	t_stacks	s;

	if (ac < 2)
		return (1);
	s = stacks_new();
	if (!parse_push_swap(ac, av, &s))
		return (finish_error(&s));
	test_push_non_sorted(&s);
	//optimize commands
	//display commands
	stacks_clear(&s);
	return (0);
}
