/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_color_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:21:24 by tignatov          #+#    #+#             */
/*   Updated: 2025/08/20 11:28:54 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	all_color_present(int *color_val)
{
	int	count_color;

	count_color = 0;
	while (count_color < NUM_KEYS2)
	{
		if (color_val[count_color] != 1)
		{
			printf("Invalid input: Wrong number of colors.\n");
			return (false);
		}
		count_color++;
	}
	return (true);
}

bool	all_texture_present(int *texture_val)
{
	int	count_text;

	count_text = 0;
	while (count_text < NUM_KEYS1)
	{
		if (texture_val[count_text] != 1)
		{
			printf("Invalid input: Wrong number of textures.\n");
			return (false);
		}
		count_text++;
	}
	return (true);
}

int	find_textures(char **map)
{
	int	i;
	int	texture_val[NUM_KEYS1] = {0};
	int	color_val[NUM_KEYS2] = {0};

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO ", 3) == 0)
			texture_val[KEY_NO]++;
		else if (ft_strncmp(map[i], "SO ", 3) == 0)
			texture_val[KEY_SO]++;
		else if (ft_strncmp(map[i], "WE ", 3) == 0)
			texture_val[KEY_WE]++;
		else if (ft_strncmp(map[i], "EA ", 3) == 0)
			texture_val[KEY_EA]++;
		else if (ft_strncmp(map[i], "C ", 2) == 0)
			color_val[KEY_C]++;
		else if (ft_strncmp(map[i], "F ", 2) == 0)
			color_val[KEY_F]++;
		i++;
	}
	if (all_color_present(color_val) == false
		|| all_texture_present(texture_val) == false)
		return (false);
	return (true);
}
