/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:03:18 by tignatov          #+#    #+#             */
/*   Updated: 2025/08/21 16:18:19 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_color_line(char *line)
{
	char	*checking_char;
	int		i;
	int		count_members;

	i = 0;
	checking_char = NULL;
	count_members = ft_count_substrings(line, ' ');
	if (count_members != 2)
		return (printf("1.Wrong input format for color.\n"), false);
	if (is_color(line))
		checking_char = line + 2;
	while (checking_char[i] != '\0')
	{
		while (checking_char[i] == ' ')
			i++;
		if (ft_isdigit(checking_char[i]) || checking_char[i] == ',')
			i++;
		else if (checking_char[i] == '\n' && checking_char[i + 1] == '\0')
			return (true);
		else
			return (printf("2.Wrong input format for color.\n"), false);
	}
	return (true);
}

bool	color_valid(char **arr)
{
	int	*int_colors;
	int	i;

	i = 0;
	int_colors = malloc(4 * sizeof(int));
	while (arr[i])
	{
		int_colors[i] = ft_atoi(arr[i]);
		if (int_colors[i] < 0 || int_colors[i] > 255)
		{
			free(int_colors);
			return (false);
		}
		i++;
	}
	free(int_colors);
	return (true);
}

void	copy_string(char *checking_char, char *color)
{
	int	i;

	i = 0;
	while (checking_char[i] && checking_char[i] != '\n')
	{
		color[i] = checking_char[i];
		i++;
	}
	color[i] = '\0';
}

bool	check_num_colors(char *color)
{
	int	num_colors;

	num_colors = 0;
	num_colors = ft_count_substrings(color, ',');
	if (num_colors != 3)
		return (printf("Invalid color values.\n"), free(color), false);
	return (true);
}

bool	is_valid_color(char *file)
{
	char	*checking_char;
	char	*color;
	char	**split_colors;

	checking_char = NULL;
	split_colors = NULL;
	while (*file && !ft_isdigit(*file))
		file++;
	checking_char = file;
	color = (char *)malloc(ft_strlen(checking_char) * sizeof(char));
	if (!color)
		return (NULL);
	copy_string(checking_char, color);
	if (check_num_colors(color) == false)
		return (false);
	split_colors = ft_split(color, ',');
	if (!split_colors)
		return (free(color), NULL);
	if (color_valid(split_colors) == false)
		return (printf("Invalid color values.\n"), free(color),
			free_2darray(split_colors), false);
	free(color);
	free_2darray(split_colors);
	return (true);
}
