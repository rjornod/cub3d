/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:58:33 by tignatov          #+#    #+#             */
/*   Updated: 2025/08/19 15:29:11 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_num_lines(char *file)
{
	int	num_lines;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	num_lines = 0;
	while (get_next_line(fd))
		num_lines++;
	close(fd);
	return (num_lines);
}

void	print_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("%s", arr[i]);
		i++;
	}
}


int	find_textures(char **map)
{
	int	i;
	int	num_texture;
	int	num_color;
	enum keys_texture {KEY_NO, KEY_SO, KEY_WE, KEY_EA, NUM_KEYS1};
	enum keys_colors {KEY_F, KEY_C, NUM_KEYS2};
	int	count_text;
	int	count_color;
	
	num_texture = 0;
	num_color = 0;
	int	texture_val[NUM_KEYS1] = {0};
	int	color_val[NUM_KEYS2] = {0};
	i = 0;
	count_text = 0;
	count_color = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO", 2) == 0)
			texture_val[KEY_NO]++;
		else if (ft_strncmp(map[i], "SO", 2) == 0)
			texture_val[KEY_SO]++;
		else if (ft_strncmp(map[i], "WE", 2) == 0)
			texture_val[KEY_WE]++;
		else if (ft_strncmp(map[i], "EA", 2) == 0)
			texture_val[KEY_EA]++;
		else if (ft_strncmp(map[i], "C", 1) == 0)
			color_val[KEY_C]++;
		else if (ft_strncmp(map[i], "F", 1) == 0)
			color_val[KEY_F]++;
		i++;
	}
	while (count_color < NUM_KEYS2)
	{
		if (color_val[count_color] != 1)
		{
			printf("wrong number of colors\n");
			return false;
		}
		count_color++;
	}
	while (count_text < NUM_KEYS1)
	{
		if (texture_val[count_text] != 1)
		{
			printf("wrong number of textures\n");
			return false;
		}
		count_text++;
	}
	printf("all tectures there\n");
	return true;
}

bool	is_map_last(char **map)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (map[i])
	{
		if (map[i + 1] && ft_strchr(map[i], '1') && ft_strchr(map[i + 1], '1'))
			found = 1;
		else if (found == 1 && map[i + 1] && ft_strchr(map[i], '1')
			&& !ft_strchr(map[i + 1], '1'))
			found = 2;
		else if (found == 2 && map[i][0] != '\n')
			return (printf("Invalid input: map is not last\n"), false);
		i++;
	}
	return (true);
}

int	parse_map(t_game *game, char *file)
{
	int	fd;
	int	num_lines;
	int	i;

	num_lines = count_num_lines(file);
	game->initial_file = (char **)malloc(sizeof(char *) * (num_lines + 1));
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	while (i < num_lines)
	{
		game->initial_file[i] = get_next_line(fd);
		if (!game->initial_file[i])
		{
			free_2darray_partial(game->initial_file, i);
			close(fd);
			break ;
		}
		i++;
	}
	game->initial_file[i] = NULL;
	close(fd);
	// print_2d_array(game->initial_file);
	return (1);
}
