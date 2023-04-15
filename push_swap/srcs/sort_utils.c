/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:03:36 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/13 18:35:27 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_arr(t_stack *s, int len)
{
	t_node	*t;
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		exit(1);
	i = -1;
	t = s->a_top;
	while (++i < len)
	{
		arr[i] = t->data;
		t = t->prev;
	}
	return (arr);
}

int	check_a_size(t_stack *s, int size)
{
	if (size == 3)
	{
		three_sort(s, 'a');
		return (0);
	}
	if (size == 2)
	{
		if (s->a_top->data > s->a_top->prev->data)
			sa(s);
		return (0);
	}
	if (size == 1 || size == 0)
		return (0);
	return (1);
}

int	check_b_size(t_stack *s, int size)
{
	if (size == 3)
	{
		three_sort(s, 'b');
		return (0);
	}
	if (size == 2)
	{
		if (s->b_top->data < s->b_top->prev->data)
			sb(s);
		pa(s);
		pa(s);
		return (0);
	}
	if (size == 1)
	{
		pa(s);
		return (0);
	}
	if (size == 0)
		return (0);
	return (1);
}

int	is_sorted_asc(t_stack *s, int size)
{
	t_node	*t;
	int		*arr;
	int		i;

	arr = init_arr(s, size);
	bubble_sort(arr, size);
	i = -1;
	t = s->a_top;
	while (++i < size)
	{
		if (arr[i] != t->data)
		{
			free(arr);
			return (0);
		}
		t = t->prev;
	}
	free(arr);
	return (1);
}

void	bubble_sort(int *arr, int size)
{
	int	tmp;
	int	i;

	while (size)
	{
		i = 0;
		while (i < (size - 1))
		{
			tmp = 0;
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
}
