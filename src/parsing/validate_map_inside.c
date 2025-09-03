/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_inside.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:00:19 by tignatov          #+#    #+#             */
/*   Updated: 2025/09/03 13:11:01 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_player_position(char **map, t_render *render, t_map *map_for_pos)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == map_for_pos->player_letter)
			{
				render->player_x = j;
				render->player_y = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_dfs_inside(char **map, size_t row, size_t col, t_map *map_dim)
{
	if (row < 0 || row >= map_dim->num_rows + 2 || col < 0
		|| col >= map_dim->max_len + 2)
		return (0);
	if (map[row][col] == '1')
		return (0);
	if (map[row][col] == ' ')
		return (1);
	map[row][col] = '1';
	if (ft_dfs_inside(map, row - 1, col, map_dim))
		return (1);
	if (ft_dfs_inside(map, row + 1, col, map_dim))
		return (1);
	if (ft_dfs_inside(map, row, col + 1, map_dim))
		return (1);
	if (ft_dfs_inside(map, row, col - 1, map_dim))
		return (1);
	return (0);
}

bool	player_count_valid(int *player_val, int player_flag, t_map *map_for_pos)
{
	int total = player_val[0] + player_val[1] + player_val[2] + player_val[3];

    if (total != 1)
    {
        printf("Invalid input: Wrong number of player.\n");
        return false;
    }
	if (player_flag == 0)
		map_for_pos->player_letter = 'N';
	else if (player_flag == 1)
		map_for_pos->player_letter = 'S';
	else if (player_flag == 2)
		map_for_pos->player_letter = 'W';
	else if (player_flag == 3)
		map_for_pos->player_letter = 'E';
	// else
	// 	return (false);
	return (true);
}

bool	count_playes(char c, int *player_val, int *player_flag)
{
	if (c != '1' && c != '0' && c != 'S' && c != 'N' && c != 'W' && c != 'E'
		&& c != ' ')
		return (printf("Invalid input: invalid chars.\n"), false);
	if (c == 'S')
	{
		player_val[KEY_S]++;
		*player_flag = 1;
	}
	else if (c == 'N')
	{
		*player_flag = 0;
		player_val[KEY_N]++;
	}
	else if (c == 'W')
	{
		*player_flag = 2;
		player_val[KEY_W]++;
	}
	else if (c == 'E')
	{
		*player_flag = 3;
		player_val[KEY_E]++;
	}
	// else
	// 	return (false);
	return (true);
}

bool	map_chars_valid(t_game *game, char **map, t_map *map_for_pos)
{
	int	player_val[4] = {0};
	int	i;
	int	j;
	int	player_flag;

	i = 0;
	player_flag = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (count_playes(map[i][j], player_val, &player_flag) == false)
				return (false);
			j++;
		}
		i++;
	}
	if (player_count_valid(player_val, player_flag, map_for_pos) == false)
		return (printf("Wrong input for player.\n"),false);
	game->map_info.player_letter = map_for_pos->player_letter;
	game->map_info.player_flag = player_flag;
	// printf("%c\n",game->map_info.player_letter);
	// printf("%i\n",game->map_info.player_flag);
	return (true);
}
