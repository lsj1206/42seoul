/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:13:22 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/13 17:14:44 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort_bb(t_stack *s, int case_num)
{
	if (case_num == 3)
	{
		pa(s);
		pa(s);
		sa(s);
		pa(s);
	}
	if (case_num == 4)
	{
		pa(s);
		sb(s);
		pa(s);
		pa(s);
	}
	if (case_num == 5)
	{
		pa(s);
		pa(s);
		pa(s);
	}
}

static void	three_sort_b(t_stack *s, int case_num)
{
	if (case_num == 0)
	{
		pa(s);
		ra(s);
		pa(s);
		pa(s);
		sa(s);
		rra(s);
	}
	if (case_num == 1)
	{
		pa(s);
		pa(s);
		sa(s);
		pa(s);
		sa(s);
	}
	if (case_num == 2)
	{
		pa(s);
		sb(s);
		pa(s);
		sa(s);
		pa(s);
	}
}

static void	three_sort_a(t_stack *s, int case_num)
{
	if (case_num == 1)
	{
		pb(s);
		sa(s);
		pa(s);
	}
	if (case_num == 2)
		sa(s);
	if (case_num == 3)
	{
		pb(s);
		sa(s);
		pa(s);
		sa(s);
	}
	if (case_num > 3)
	{
		sa(s);
		pb(s);
		sa(s);
		pa(s);
	}
	if (case_num == 5)
		sa(s);
}

static int	check_case(t_stack *s, int *arr, int stack_name)
{
	t_node	*t;

	t = s->a_top;
	if (stack_name == 'b')
		t = s->b_top;
	if (t->data == arr[0])
	{
		if (t->prev->data == arr[1])
			return (0);
		return (1);
	}
	if (t->data == arr[1])
	{
		if (t->prev->data == arr[0])
			return (2);
		return (3);
	}
	if (t->data == arr[2])
	{
		if (t->prev->data == arr[0])
			return (4);
		return (5);
	}
	exit(1);
}

void	three_sort(t_stack *s, int stack_name)
{
	t_node	*t;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * 3);
	if (!arr)
		exit(1);
	t = s->a_top;
	if (stack_name == 'b')
		t = s->b_top;
	i = -1;
	while (++i < 3)
	{
		arr[i] = t->data;
		t = t->prev;
	}
	bubble_sort(arr, 3);
	if (stack_name == 'a')
		three_sort_a(s, check_case(s, arr, 'a'));
	if (stack_name == 'b' && (check_case(s, arr, 'b') < 3))
		three_sort_b(s, check_case(s, arr, 'b'));
	else if (stack_name == 'b' && (check_case(s, arr, 'b') > 2))
		three_sort_bb(s, check_case(s, arr, 'b'));
	free(arr);
}
