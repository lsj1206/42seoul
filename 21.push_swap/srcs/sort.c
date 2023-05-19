/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:46:07 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/14 10:57:15 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_stack *s, int size)
{
	t_cmd_cnt	cnt;

	cnt.pb = 0;
	cnt.ra = 0;
	cnt.rb = 0;
	if (!check_a_size(s, size))
		return ;
	if (is_sorted_asc(s, size))
		return ;
	div_atob(s, &cnt, size);
	restore(s, cnt.ra, cnt.rb);
	sort_a(s, cnt.ra);
	sort_b(s, cnt.rb);
	sort_b(s, cnt.pb - cnt.rb);
}

void	sort_b(t_stack *s, int size)
{
	t_cmd_cnt	cnt;

	cnt.pa = 0;
	cnt.ra = 0;
	cnt.rb = 0;
	if (!check_b_size(s, size))
		return ;
	div_btoa(s, &cnt, size);
	sort_a(s, cnt.pa - cnt.ra);
	restore(s, cnt.ra, cnt.rb);
	sort_a(s, cnt.ra);
	sort_b(s, cnt.rb);
}

void	div_atob(t_stack *s, t_cmd_cnt *cnt, int size)
{
	t_pivot	pivot;
	int		tmp_size;
	int		t;

	tmp_size = size;
	pivot = init_pivot_a(s, size);
	while (tmp_size--)
	{
		t = s->a_top->data;
		if (t < pivot.l)
		{
			pb(s);
			cnt->pb++;
			if (t > pivot.s)
			{
				rb(s);
				cnt->rb++;
			}
		}
		else
		{
			ra(s);
			cnt->ra++;
		}
	}
}

void	div_btoa(t_stack *s, t_cmd_cnt *cnt, int size)
{
	t_pivot	pivot;
	int		tmp_size;
	int		t;

	tmp_size = size;
	pivot = init_pivot_b(s, size);
	while (tmp_size--)
	{
		t = s->b_top->data;
		if (t >= pivot.s)
		{
			pa(s);
			cnt->pa++;
			if (t <= pivot.l)
			{
				ra(s);
				cnt->ra++;
			}
		}
		else
		{
			rb(s);
			cnt->rb++;
		}
	}
}

void	restore(t_stack *s, int ra_cnt, int rb_cnt)
{
	while (ra_cnt && rb_cnt)
	{
		ra_cnt--;
		rb_cnt--;
		rrr(s);
	}
	while (ra_cnt--)
	{
		rra(s);
	}
	while (rb_cnt--)
		rrb(s);
}
