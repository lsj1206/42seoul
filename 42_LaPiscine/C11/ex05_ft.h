/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:13:38 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/14 17:37:55 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_H
# define FT_H

# include <unistd.h>

int			ft_sum(int a, int b);
int			ft_sub(int a, int b);
int			ft_mul(int a, int b);
int			ft_div(int a, int b);
int			ft_mod(int a, int b);

int			ft_is_op(char c);
int			ft_ck_op(char **str);
int			ft_print_error(int op, int b);
void		ft_fcase(int (**fc)(int, int));

int			ft_atoi(char *str);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);
long long	ft_nbr(long long n);

#endif
