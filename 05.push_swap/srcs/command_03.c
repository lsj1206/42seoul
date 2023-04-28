/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:32:14 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/14 11:04:54 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *s)
{
	rra(s);
	rrb(s);
}

void	rra(t_stack *s)
{
	int	tmp;

	if (s->a_size < 2)
		return ;
	tmp = s->a_bottom->data;
	pop_a_bottom(s);
	push_a(s, tmp);
	add_print_list(s, "rra\n");
}

void	rrb(t_stack *s)
{
	int	tmp;

	if (s->b_size < 2)
		return ;
	tmp = s->b_bottom->data;
	pop_b_bottom(s);
	push_b(s, tmp);
	add_print_list(s, "rrb\n");
}

void	pop_a_bottom(t_stack *s)
{
	t_node	*del_node;

	if (!(s->a_size))
		return ;
	if (s->a_size == 1)
	{
		free(s->a_bottom);
		s->a_bottom = 0;
		s->a_size--;
		return ;
	}
	del_node = s->a_bottom;
	s->a_bottom->next->prev = 0;
	s->a_bottom = s->a_bottom->next;
	s->a_size--;
	free(del_node);
}

void	pop_b_bottom(t_stack *s)
{
	t_node	*del_node;

	if (!(s->b_size))
		return ;
	del_node = s->b_bottom;
	if (s->b_size == 1)
	{
		free(s->b_bottom);
		s->b_bottom = 0;
		s->b_size--;
		return ;
	}
	del_node = s->b_bottom;
	s->b_bottom->next->prev = 0;
	s->b_bottom = s->b_bottom->next;
	s->b_size--;
	free(del_node);
}
