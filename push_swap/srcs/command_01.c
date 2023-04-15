/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:15:55 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/14 11:05:42 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *s)
{
	sa(s);
	sb(s);
}

void	sa(t_stack *s)
{
	int	tmp_data;

	if (s->a_size < 2)
		return ;
	tmp_data = s->a_top->data;
	s->a_top->data = s->a_top->prev->data;
	s->a_top->prev->data = tmp_data;
	add_print_list(s, "sa\n");
	return ;
}

void	sb(t_stack *s)
{
	int	tmp_data;

	if (s->b_size < 2)
		return ;
	tmp_data = s->b_top->data;
	s->b_top->data = s->b_top->prev->data;
	s->b_top->prev->data = tmp_data;
	add_print_list(s, "sb\n");
	return ;
}

void	pa(t_stack *s)
{
	int	data;

	if (!s->b_size)
		return ;
	data = s->b_top->data;
	push_a(s, data);
	pop_b(s);
	add_print_list(s, "pa\n");
}

void	pb(t_stack *s)
{
	int	data;

	if (!s->a_size)
		return ;
	data = s->a_top->data;
	push_b(s, data);
	pop_a(s);
	add_print_list(s, "pb\n");
}
