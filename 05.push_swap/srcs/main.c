/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:09:53 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/20 16:33:43 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*s;
	t_stack	*printer;
	int		size;

	(void)ac;
	init_stacks(&s);
	parsing(s, av);
	size = s->a_size;
	if (is_sorted_asc(s, size))
	{
		free_stack(s);
		free(s);
		return (0);
	}
	if (size < 6)
		case_only(s, size);
	else
		sort_a(s, size);
	init_stacks(&printer);
	print_command(s, printer);
	free_stack(s);
	free(s);
	free(printer);
	return (0);
}
