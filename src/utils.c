/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:53:21 by tignatov          #+#    #+#             */
/*   Updated: 2025/09/02 14:17:14 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	count_num_lines(char *file)
{
	int	num_lines;
	int	fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (false);
	num_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		num_lines++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (num_lines);
}

void	print_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("[%s]\n", arr[i]);
		i++;
	}
}

int	ft_count_substrings(const char *s, char c)
{
	int	i;
	int	count;
	int	in_substring;

	i = 0;
	count = 0;
	in_substring = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !in_substring)
		{
			in_substring = 1;
			count++;
		}
		else if (s[i] == c)
			in_substring = 0;
		i++;
	}
	return (count);
}

int	init_game_parsing(t_game *game)
{
	game->colors = NULL;
	game->colors = (t_color *)malloc(sizeof(t_color));
	if (!game->colors)
		return (0);
	game->colors->c_rgb = (unsigned long)0;
	game->colors->f_rgb = (unsigned long)0;
	game->textures = (t_texture *)malloc(sizeof(t_texture));
	if (!game->textures)
		return (free(game->colors), 0);
	game->textures->e_text = NULL;
	game->textures->w_text = NULL;
	game->textures->n_text = NULL;
	game->textures->s_text = NULL;
	return (1);
}
