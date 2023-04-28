/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:35:20 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/16 13:05:03 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_two(t_stack *s)
{
	if (s->a_top->data > s->a_top->prev->data)
		sa(s);
	return ;
}

void	only_three(t_stack *s)
{
	int		*arr;

	arr = init_arr(s, 3);
	bubble_sort(arr, 3);
	if (find_pos(s, arr[2]) == 1)
		rra(s);
	if (find_pos(s, arr[2]) == 0)
		ra(s);
	if (s->a_top->data != arr[0])
		sa(s);
	free(arr);
}

void	only_four(t_stack *s)
{
	int		*arr;

	arr = init_arr(s, 4);
	bubble_sort(arr, 4);
	if (find_pos(s, arr[0]) == 1 || \
		((find_pos(s, arr[0]) == 2) && (find_pos(s, arr[3]) == 1)))
		sa(s);
	else if (find_pos(s, arr[0]) == 3 || \
			((find_pos(s, arr[0]) == 2) && (find_pos(s, arr[3]) == 3)))
		rra(s);
	pb(s);
	only_three(s);
	pa(s);
	if (!find_pos(s, arr[3]))
		ra(s);
	free(arr);
}

void	only_five(t_stack *s)
{
	int		*arr;

	arr = init_arr(s, 5);
	bubble_sort(arr, 5);
	if (find_pos(s, arr[0]) == 2 || find_pos(s, arr[0]) == 3)
		make_four(s, find_pos(s, arr[4]));
	else
		make_four(s, find_pos(s, arr[0]));
	only_four(s);
	pa(s);
	if (s->a_top->data > s->a_top->prev->data)
		ra(s);
	free(arr);
}
