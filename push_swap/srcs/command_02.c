/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:15:56 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/14 11:04:50 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *s)
{
	ra(s);
	rb(s);
}

void	ra(t_stack *s)
{
	t_node	*new_node;
	int		tmp;

	if (!(s->a_size))
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	tmp = s->a_top->data;
	pop_a(s);
	new_node->data = tmp;
	new_node->next = s->a_bottom;
	new_node->prev = NULL;
	if (!s->a_size)
	{
		s->a_top = new_node;
		new_node->prev = 0;
		new_node->next = 0;
	}
	else
		s->a_bottom->prev = new_node;
	s->a_bottom = new_node;
	s->a_size++;
	add_print_list(s, "ra\n");
}

void	rb(t_stack *s)
{
	t_node	*new_node;
	int		tmp;

	if (!(s->b_size))
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	tmp = s->b_top->data;
	pop_b(s);
	new_node->data = tmp;
	new_node->next = s->b_bottom;
	new_node->prev = NULL;
	if (!s->b_size)
	{
		s->b_top = new_node;
		new_node->prev = 0;
		new_node->next = 0;
	}
	else
		s->b_bottom->prev = new_node;
	s->b_bottom = new_node;
	s->b_size++;
	add_print_list(s, "rb\n");
}
