/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:36:38 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/12 18:24:16 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *s, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->data = data;
	new_node->next = 0;
	if (!(s->a_size))
	{
		new_node->prev = 0;
		s->a_top = new_node;
		s->a_bottom = new_node;
		s->a_size++;
		return ;
	}
	new_node->prev = s->a_top;
	s->a_top->next = new_node;
	s->a_top = new_node;
	s->a_size++;
}

void	push_b(t_stack *s, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->data = data;
	new_node->next = 0;
	if (!(s->b_size))
	{
		new_node->prev = 0;
		s->b_top = new_node;
		s->b_bottom = new_node;
		s->b_size++;
		return ;
	}
	new_node->prev = s->b_top;
	s->b_top->next = new_node;
	s->b_top = new_node;
	s->b_size++;
}

void	pop_a(t_stack *s)
{
	t_node	*del_node;
	t_node	*tmp_node;

	if (!(s->a_top) || s->a_size == 0)
		return ;
	if (!(s->a_top->prev) || s->a_size == 1)
	{
		free(s->a_top);
		s->a_top = 0;
		s->a_size--;
		return ;
	}
	del_node = s->a_top;
	tmp_node = s->a_top->prev;
	tmp_node->next = 0;
	s->a_top = tmp_node;
	free(del_node);
	s->a_size--;
}

void	pop_b(t_stack *s)
{
	t_node	*del_node;
	t_node	*tmp_node;

	if (!(s->b_top) || s->b_size == 0)
		return ;
	if (!(s->b_top->prev) || s->b_size == 1)
	{
		free(s->b_top);
		s->b_top = 0;
		s->b_size--;
		return ;
	}
	del_node = s->b_top;
	tmp_node = s->b_top->prev;
	tmp_node->next = 0;
	s->b_top = tmp_node;
	free(del_node);
	s->b_size--;
}
