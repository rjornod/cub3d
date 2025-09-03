/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_outer_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:02:45 by tignatov          #+#    #+#             */
/*   Updated: 2025/09/03 13:02:37 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_dfs(char **map, size_t row, size_t col, t_map *map_dim)
{
	if (row < 0 || row >= map_dim->num_rows + 2 || col < 0
		|| col >= map_dim->max_len + 2)
		return (0);
	if (map[row][col] == '1')
		return (0);
	if (map[row][col] != ' ')
		return (1);
	map[row][col] = '1';
	if (ft_dfs(map, row - 1, col, map_dim))
		return (1);
	if (ft_dfs(map, row + 1, col, map_dim))
		return (1);
	if (ft_dfs(map, row, col + 1, map_dim))
		return (1);
	if (ft_dfs(map, row, col - 1, map_dim))
		return (1);
	return (0);
}

char	**dup_array(char **income_map)
{
	char	**map;
	size_t	i;
	size_t	num_rows;
	size_t	len;

	num_rows = 0;
	i = 0;
	while (income_map[num_rows])
		num_rows++;
	map = (char **)malloc((num_rows + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (i < num_rows)
	{
		len = ft_strlen(income_map[i]);
		map[i] = (char *)malloc(len + 1);
		if (!map[i])
			return (free_2darray_partial(map, i), NULL);
		ft_strncpy(map[i], income_map[i], len);
		map[i][len] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	validate_map(t_game *game, char **initial_file, t_render *render)
{
	t_map	map;
	char	**map_to_valid;
	char	**tmp;

	game->map = NULL;
	map = find_map_size(initial_file);
	map_to_valid = map_for_valid(initial_file, &map);
	if (!map_to_valid)
		return (0);
	print_2d_array(map_to_valid);
	tmp = dup_array(map_to_valid);
	if (!tmp)
		return (free_2darray(map_to_valid), 0);
	if (ft_dfs(tmp, 0, 0, &map) || map_chars_valid(game, tmp, &map) == false)
		return (printf("1.Map is invalid.\n"), free_2darray(tmp),
			free_2darray(map_to_valid), 0);
	find_player_position(tmp, render, &map);
	if (ft_dfs_inside(tmp, (size_t)render->player_y, (size_t)render->player_x,
			&map) == true)
		return (printf("2.Map is invalid. Empty spaces.\n"), free_2darray(tmp),
			free_2darray(map_to_valid), 0);
	game->map = map_to_valid;
	// print_2d_array(game->map);
	free_2darray(tmp);
	printf("Map is valid.\n");
	return (1);
}
