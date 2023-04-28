/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_case_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:20:40 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/16 13:05:08 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_only(t_stack *s, int size)
{
	if (size == 2)
		only_two(s);
	else if (size == 3)
		only_three(s);
	else if (size == 4)
		only_four(s);
	else if (size == 5)
		only_five(s);
}

int	find_pos(t_stack *s, int value)
{
	t_node	*t;
	int		index;

	index = 0;
	t = s->a_top;
	while (t)
	{
		if (t->data == value)
			break ;
		t = t->prev;
		index++;
	}
	return (index);
}

void	make_four(t_stack *s, int index)
{
	if (index == 0)
		pb(s);
	else if (index == 1)
	{
		sa(s);
		pb(s);
	}
	else if (index == 4)
	{
		rra(s);
		pb(s);
	}
	else
	{
		rra(s);
		rra(s);
		pb(s);
	}
}
