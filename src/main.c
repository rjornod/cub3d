/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:58:39 by tignatov          #+#    #+#             */
/*   Updated: 2025/08/19 16:56:55 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (int argc, char **argv)
{
    t_game  	game;
	t_render	*render;
	
	printf("Hello!");
 	if (is_valid_input(argc, argv) == false)
		return (1);
	parse_map(&game, argv[1]);
	printf("%s\n", game.initial_file[0]);
	render = init_render();
	mlx_start(render);
	mlx_key_hook(render->mlx, &key_handler, render);
	mlx_loop_hook(render->mlx, &draw_player, render);
	mlx_loop(render->mlx);
	mlx_terminate(render->mlx);
	free(render); //needs to be freed somewhere else
}  

// int main (int argc, char **argv)
// {
//     t_game  	game;
// 	t_render	*render;
	
//     if (is_valid_input(argc, argv) == false)
// 	{
// 		printf("Invalid input\n");
// 		return (1);
// 	}
//     parse_map(&game, argv[1]);
// 	is_map_last(game.initial_file);
// 	find_textures(game.initial_file);
// 	// render = init_render();
// 	// mlx_start(render);
// 	// mlx_key_hook(render->mlx, &key_handler, render);
// 	// mlx_loop_hook(render->mlx, &draw_player, render);
// 	// mlx_loop(render->mlx);
// 	// mlx_terminate(render->mlx);
// 	// free(render); //needs to be freed somewhere else
// }