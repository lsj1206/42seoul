/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:29:07 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/20 15:05:26 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	struct node	*next;
	struct node	*prev;
	int			data;
}		t_node;

typedef struct cmd_list
{
	struct cmd_list	*next;
	struct cmd_list	*prev;
	char			*cmd;
}		t_cmd;

typedef struct stack
{
	t_cmd	*print_list;
	t_node	*a_top;
	t_node	*a_bottom;
	t_node	*b_top;
	t_node	*b_bottom;
	int		a_size;
	int		b_size;
}		t_stack;

typedef struct cmd_counter
{
	int	pa;
	int	pb;
	int	ra;
	int	rb;
}	t_cmd_cnt;

typedef struct s_pivot
{
	int	s;
	int	l;
}	t_pivot;

char		**init_data(char **av);
void		parsing(t_stack *s, char **av);
void		free_parsing(char **str, int *arr);
void		init_stacks(t_stack **s);
void		free_stack(t_stack *s);
void		error_print(void);
void		error_input(char *str);
void		error_overlap(int *arr, int len);

int			*init_arr(t_stack *s, int len);
int			is_sorted_asc(t_stack *s, int size);
int			check_a_size(t_stack *s, int size);
int			check_b_size(t_stack *s, int size);
void		sort_a(t_stack *s, int size);
void		sort_b(t_stack *s, int size);
void		div_atob(t_stack *s, t_cmd_cnt *cnt, int size);
void		div_btoa(t_stack *s, t_cmd_cnt *cnt, int size);
void		restore(t_stack *s, int ra_cnt, int rb_cnt);
void		three_sort(t_stack *s, int stack_name);
void		bubble_sort(int *arr, int size);
t_pivot		init_pivot_a(t_stack *s, int size);
t_pivot		init_pivot_b(t_stack *s, int size);

void		case_only(t_stack *s, int size);
void		only_two(t_stack *s);
void		only_three(t_stack *s);
void		only_four(t_stack *s);
void		only_five(t_stack *s);
void		make_four(t_stack *s, int index);
int			find_pos(t_stack *s, int value);

void		ss(t_stack *s);
void		sa(t_stack *s);
void		sb(t_stack *s);
void		pa(t_stack *s);
void		pb(t_stack *s);
void		ra(t_stack *s);
void		rb(t_stack *s);
void		rr(t_stack *s);
void		rra(t_stack *s);
void		rrb(t_stack *s);
void		rrr(t_stack *s);

void		push_a(t_stack *s, int data);
void		push_b(t_stack *s, int data);
void		pop_a(t_stack *s);
void		pop_b(t_stack *s);;
void		pop_a_bottom(t_stack *s);
void		pop_b_bottom(t_stack *s);

void		print_command(t_stack *s, t_stack *p);
void		optimize_command(t_stack *s, t_stack *p, char *s1, char *s2);
void		op_print_list(t_stack *s, t_stack *p, char *str);
void		add_print_list(t_stack *s, char	*str);
void		del_print_list(t_stack *s);

int			ft_isdigit(int c);
int			ft_strcmp(const char *s1, const char *s2);
long long	ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);

#endif
