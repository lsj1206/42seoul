/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:06:31 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/16 13:08:16 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_print_list(t_stack *s, char *str)
{
	t_cmd	*new_cmd;

	new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_cmd)
		exit(1);
	new_cmd->cmd = ft_strdup(str);
	new_cmd->next = 0;
	if (!(s->print_list))
	{
		new_cmd->prev = 0;
		s->print_list = new_cmd;
		return ;
	}
	new_cmd->prev = s->print_list;
	s->print_list->next = new_cmd;
	s->print_list = new_cmd;
}

void	del_print_list(t_stack *s)
{
	t_cmd	*del_list;
	t_cmd	*tmp_list;

	if (!s->print_list)
		return ;
	if (!s->print_list->prev)
	{
		free(s->print_list->cmd);
		free(s->print_list);
		s->print_list = 0;
		return ;
	}
	tmp_list = s->print_list->prev;
	tmp_list->next = 0;
	del_list = s->print_list;
	free(del_list->cmd);
	free(del_list);
	s->print_list = tmp_list;
}

void	op_print_list(t_stack *s, t_stack *p, char *str)
{
	add_print_list(p, str);
	del_print_list(s);
	del_print_list(s);
}

void	optimize_command(t_stack *s, t_stack *p, char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "sa\n") && !ft_strcmp(s2, "sb\n")) || \
		(!ft_strcmp(s1, "sb\n") && !ft_strcmp(s2, "sa\n")))
		op_print_list(s, p, "ss\n");
	else if ((!ft_strcmp(s1, "ra\n") && !ft_strcmp(s2, "rb\n")) || \
			(!ft_strcmp(s1, "rb\n") && !ft_strcmp(s2, "ra\n")))
		op_print_list(s, p, "rr\n");
	else if ((!ft_strcmp(s1, "rra\n") && !ft_strcmp(s2, "rrb\n")) || \
			(!ft_strcmp(s1, "rrb\n") && !ft_strcmp(s2, "rra\n")))
		op_print_list(s, p, "rrr\n");
	else
	{
		add_print_list(p, s1);
		del_print_list(s);
	}
}

void	print_command(t_stack *s, t_stack *p)
{
	t_cmd	*t;

	if (!s->print_list)
		return ;
	t = s->print_list;
	while (t)
	{
		t = s->print_list;
		if (t->prev)
			optimize_command(s, p, t->cmd, t->prev->cmd);
		else
		{
			add_print_list(p, t->cmd);
			del_print_list(s);
			break ;
		}
	}
	t = p->print_list;
	while (t)
	{
		write(1, t->cmd, ft_strlen(t->cmd));
		del_print_list(p);
		t = p->print_list;
	}
}
