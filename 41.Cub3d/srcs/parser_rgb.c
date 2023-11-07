/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:54:58 by seojulee          #+#    #+#             */
/*   Updated: 2023/10/27 20:32:25 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static unsigned int	extract_rgb(t_data *d, char *str)
{
	char	*tmp;
	int		color;
	int		len;
	int		i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]))
			break ;
	len = i;
	while (str[len] != '\0')
		if (!ft_isdigit(str[++len]))
			break ;
	tmp = ft_substr(str, i, (len - i));
	if (!tmp)
		err_handler(d, ERR_MEM, str);
	color = ft_atoi(tmp);
	free(tmp);
	if (color > 255 || color < 0)
		err_handler(d, ERR_ARG, str);
	return (color);
}

static void	vaild_rgb(t_data *d, char *str)
{
	int	i;
	int	is_comma;
	int	is_digit;

	i = -1;
	is_comma = 0;
	is_digit = 0;
	while (str[++i] != '\0')
	{
		if (ft_isdigit(str[i]))
			is_digit++;
		else if (str[i] == ',')
			is_comma++;
		else
			err_handler(d, ERR_ARG, str);
	}
	if (is_comma > 2 || is_digit > 9)
		err_handler(d, ERR_ARG, str);
}

int	parse_rgb(t_data *d, char *str)
{
	int	color_r;
	int	color_g;
	int	color_b;

	vaild_rgb(d, str);
	color_r = extract_rgb(d, str);
	color_g = extract_rgb(d, ft_strchr(str, ','));
	color_b = extract_rgb(d, ft_strrchr(str, ','));
	return (((color_r << 16) | (color_g << 8) | color_b) + 1);
}
