/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:02:45 by tignatov          #+#    #+#             */
/*   Updated: 2025/09/03 14:36:03 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	find_map_size(char **file)
{
	t_map	map = {0, 0, '\0', -1};
	size_t	curr_len;
	int		i;

	i = 0;
    map.max_len = 0;
    map.num_rows = 0;
	while (file[i] && (is_color(file[i]) || is_texture(file[i])
			|| !(ft_strchr(file[i], '1'))))
		i++;
	while (file[i] && ft_strchr(file[i], '1'))
	{
		curr_len = ft_strlen(file[i]);
		if (curr_len > map.max_len)
			map.max_len = curr_len;
		map.num_rows++;
		i++;
	}
	return (map);
}

int	malloc_map(char **map, t_map *map_dim)
{
	size_t	i;

	i = 0;
	while (i < (map_dim->num_rows + 2))
	{
		map[i] = (char *)malloc(map_dim->max_len + 2 + 1);
		// printf("%zu\n",map_dim->max_len);
		if (!map[i])
			return (free_2darray_partial(map, i), 0);
		i++;
	}
	map[i] = NULL;
	return (1);
}

void	fill_with_space(char *extrac_map, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		extrac_map[i] = ' ';
		i++;
	}
	extrac_map[i] = '\0';
}

void	copy_line(char *file_line, char *result_line, t_map *map_dim)
{
	int		i;
	size_t	k;

	i = 0;
	k = 0;
	while (file_line[i] == ' ' || file_line[i] == '\t')
	{
		result_line[k] = ' ';
		i++;
		k++;
	}
	result_line[k++] = ' ';
	while (file_line[i] != '\0' && file_line[i] != '\n' && k < map_dim->max_len + 1)
		result_line[k++] = file_line[i++];
	while (k < map_dim->max_len + 1)
		result_line[k++] = ' ';
	result_line[k++] = ' ';
	// while (file_line[i] != '\0')
	// {
	// 	if (k == 0 || k == map_dim->max_len + 2)
	// 	{
	// 		result_line[k] = ' ';
	// 		k++;
	// 	}
	// 	if (file_line[i] == '\n')
	// 		result_line[k] = ' ';
	// 	else
	// 		result_line[k] = file_line[i];
	// 	i++;
	// 	k++;
	// }
	// while (k < map_dim->max_len + 2)
	// {
	// 	result_line[k] = ' ';
	// 	k++;
	// }
	result_line[k] = '\0';
}

char	**map_for_valid(char **file, t_map *map_dim)
{
	int		i;
	size_t	k;
	char	**extrac_map;

	i = 0;
	extrac_map = (char **)malloc((map_dim->num_rows + 2 + 1) * sizeof(char *));
	// printf("%zu\n",map_dim->num_rows);
	if (!extrac_map)
		return (NULL);
	if (!malloc_map(extrac_map, map_dim))
		return (free(extrac_map), NULL);
	fill_with_space(extrac_map[0], map_dim->max_len + 2);
	while (file[i] && (is_color(file[i]) || is_texture(file[i])
			|| !(ft_strchr(file[i], '1'))))
		i++;
	k = 1;
	while (file[i] && ft_strchr(file[i], '1'))
	{
		copy_line(file[i], extrac_map[k], map_dim);
		i++;
		k++;
	}
	fill_with_space(extrac_map[k], map_dim->max_len + 2);
	k++;
	extrac_map[k] = NULL;
	return (extrac_map);
}
