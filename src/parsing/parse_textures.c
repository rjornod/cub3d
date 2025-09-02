/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:32:38 by tignatov          #+#    #+#             */
/*   Updated: 2025/08/29 13:27:46 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	first_letters(t_game *game, char *start_pars, char c, int len)
{
	if (c == 'N')
	{
		game->textures->n_text = (char *)malloc(len * sizeof(char));
		if (!game->textures->n_text)
			return (0);
		ft_strncpy(game->textures->n_text, start_pars, len - 1);
		game->textures->n_text[len - 1] = '\0';
	}
	else if (c == 'S')
	{
		game->textures->s_text = (char *)malloc(len * sizeof(char));
		if (!game->textures->s_text)
			return (free(game->textures->n_text), 0);
		ft_strncpy(game->textures->s_text, start_pars, len - 1);
		game->textures->s_text[len - 1] = '\0';
	}
	return (1);
}

int	second_letters(t_game *game, char *start_pars, char c, int len)
{
	if (c == 'E')
	{
		game->textures->e_text = (char *)malloc(len * sizeof(char));
		if (!game->textures->e_text)
			return (free(game->textures->n_text), free(game->textures->s_text),
				0);
		ft_strncpy(game->textures->e_text, start_pars, len - 1);
		game->textures->e_text[len - 1] = '\0';
	}
	else if (c == 'W')
	{
		game->textures->w_text = (char *)malloc(len * sizeof(char));
		if (!game->textures->w_text)
			return (free(game->textures->e_text), free(game->textures->n_text),
				free(game->textures->s_text), 0);
		ft_strncpy(game->textures->w_text, start_pars, len - 1);
		game->textures->w_text[len - 1] = '\0';
	}
	return (1);
}

int	malloc_copy_texture(t_game *game, char *start_pars, char c)
{
	size_t	len;

	len = ft_strlen(start_pars);
	if (!first_letters(game, start_pars, c, len))
		return (0);
	if (!second_letters(game, start_pars, c, len))
		return (0);
	return (1);
}

int	parsing_paths(t_game *game, char c)
{
	int		i;
	char	*start_pars;

	i = 0;
	while (game->initial_file[i])
	{
		start_pars = ft_strchr(game->initial_file[i], c);
		if (start_pars != NULL)
			break ;
		i++;
	}
	while (*start_pars && *start_pars != '.')
		start_pars++;
	if (!malloc_copy_texture(game, start_pars, c))
		return (0);
	return (1);
}

int	parse_textures(t_game *game)
{
	if (!parsing_paths(game, 'N'))
		return (0);
	if (!parsing_paths(game, 'S'))
		return (0);
	if (!parsing_paths(game, 'W'))
		return (0);
	if (!parsing_paths(game, 'E'))
		return (0);
	// printf("%s\n", game->textures->n_text);
	// printf("%s\n", game->textures->w_text);
	return (1);
}
