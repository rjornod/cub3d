/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:46:22 by tignatov          #+#    #+#             */
/*   Updated: 2025/08/29 12:53:02 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	convert_rgb(int *rgb)
{
	return ((rgb[0] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + (rgb[2] & 0xff);
}

char	**find_copy_color_c(char **file)
{
	char	*c_color;
	char	*color;
	int		i;
	char	**split_colors;

	i = 0;
	while (file[i])
	{
		c_color = ft_strchr(file[i], 'C');
		if (c_color != NULL)
			break ;
		i++;
	}
	while (*c_color && !ft_isdigit(*c_color))
		c_color++;
	color = (char *)malloc(ft_strlen(c_color) * sizeof(char));
	if (!color)
		return (0);
	copy_string(c_color, color);
	split_colors = ft_split(color, ',');
	free(color);
	return (split_colors);
}

int	parse_color_c(t_game *game)
{
	char	**file;
	char	**split_colors;
	int		rgb[3] = {0, 0, 0};

	split_colors = NULL;
	file = game->initial_file;
	split_colors = find_copy_color_c(file);
	if (!split_colors)
		return (free_2darray(split_colors), 0);
	rgb[0] = ft_atoi(split_colors[0]);
	rgb[1] = ft_atoi(split_colors[1]);
	rgb[2] = ft_atoi(split_colors[2]);
	game->colors->c_rgb = convert_rgb(rgb);
	free_2darray(split_colors);
	return (1);
}

char	**find_copy_color_f(char **file)
{
	char	*f_color;
	char	*color;
	int		i;
	char	**split_colors;

	i = 0;
	while (file[i])
	{
		f_color = ft_strchr(file[i], 'F');
		if (f_color != NULL)
			break ;
		i++;
	}
	while (*f_color && !ft_isdigit(*f_color))
		f_color++;
	color = (char *)malloc(ft_strlen(f_color) * sizeof(char));
	if (!color)
		return (0);
	copy_string(f_color, color);
	split_colors = ft_split(color, ',');
	free(color);
	return (split_colors);
}

int	parse_color_f(t_game *game)
{
	char	**file;
	char	**split_colors;
	int		rgb[3] = {0, 0, 0};

	split_colors = NULL;
	file = game->initial_file;
	split_colors = find_copy_color_f(file);
	if (!split_colors)
		return (free_2darray(split_colors), 0);
	rgb[0] = ft_atoi(split_colors[0]);
	rgb[1] = ft_atoi(split_colors[1]);
	rgb[2] = ft_atoi(split_colors[2]);
	game->colors->f_rgb = convert_rgb(rgb);
	free_2darray(split_colors);
	return (1);
}

int	parse_colors(t_game *game)
{
	if (!parse_color_f(game))
		return (0);
	if (!parse_color_c(game))
		return (0);
	// printf("%lX\n", game->colors->c_rgb);
	// printf("%lX\n", game->colors->f_rgb);
	return (1);
}
