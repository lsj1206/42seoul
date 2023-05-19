/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:11:35 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/20 16:28:12 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack **s)
{
	*s = (t_stack *)malloc(sizeof(t_stack));
	if (!*s)
		exit(1);
	(*s)->print_list = 0;
	(*s)->a_top = 0;
	(*s)->a_bottom = 0;
	(*s)->a_size = 0;
	(*s)->b_top = 0;
	(*s)->b_bottom = 0;
	(*s)->b_size = 0;
}

char	**init_data(char **av)
{
	char	**data;
	char	*str;
	char	*tmp;
	int		i;

	str = (char *)malloc(1);
	if (!str)
		exit(1);
	*str = 0;
	i = 0;
	while (av[++i])
	{
		error_input(av[i]);
		tmp = str;
		str = ft_strjoin(str, av[i]);
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
	}
	data = ft_split(str, ' ');
	free(str);
	return (data);
}

void	free_stack(t_stack *s)
{
	while (s->a_size)
		pop_a(s);
	while (s->b_size)
		pop_b(s);
}

void	free_parsing(char **str, int *arr)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	while (len)
		free(str[--len]);
	free(str);
	free(arr);
}

void	parsing(t_stack *s, char **av)
{
	char		**str;
	long long	tmp;
	int			*arr;
	int			len;
	int			i;

	str = init_data(av);
	len = 0;
	while (str[len])
		len++;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		exit(1);
	i = -1;
	while (++i < len)
	{
		tmp = ft_atoi(str[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			error_print();
		arr[i] = tmp;
	}
	error_overlap(arr, len);
	while (len)
		push_a(s, arr[--len]);
	free_parsing(str, arr);
}
