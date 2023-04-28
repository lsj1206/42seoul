/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:14:28 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/06 18:08:34 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		str_read(va_list ap, int i, char *str, int read_byte);
int		spec_check(va_list ap, int i, char *str);
int		spec_is_c(va_list ap);
int		spec_is_s(va_list ap);
int		spec_is_p(va_list ap);
int		spec_is_d_i(va_list ap);
int		spec_is_u_x(va_list ap, size_t base, size_t upper_flag);
size_t	str_len(const char *str);
size_t	num_len(long long n, size_t nbase);
size_t	num_len_to_unsigned(unsigned long long n, size_t nbase);
char	*num_to_str(long long n, size_t base_flag, size_t upper_flag);
char	*addr_to_hex(void *p);
#endif
