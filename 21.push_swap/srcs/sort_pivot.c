/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:29:33 by wmo               #+#    #+#             */
/*   Updated: 2023/02/14 10:53:42 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pivot	init_pivot_a(t_stack *s, int size)
{
	t_pivot	pivot;
	t_node	*t;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	i = -1;
	t = s->a_top;
	while (++i < size)
	{
		arr[i] = t->data;
		t = t->prev;
	}
	bubble_sort(arr, size);
	pivot.s = arr[size / 3];
	pivot.l = arr[size / 3 * 2];
	free(arr);
	return (pivot);
}

t_pivot	init_pivot_b(t_stack *s, int size)
{
	t_pivot	pivot;
	t_node	*t;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	i = -1;
	t = s->b_top;
	while (++i < size)
	{
		arr[i] = t->data;
		t = t->prev;
	}
	bubble_sort(arr, size);
	pivot.s = arr[size / 3];
	pivot.l = arr[size / 3 * 2];
	free(arr);
	return (pivot);
}
