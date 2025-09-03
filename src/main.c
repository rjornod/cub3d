/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:58:39 by tignatov          #+#    #+#             */
/*   Updated: 2025/08/25 13:14:09 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	free_render(t_render *render)
// {
// 	free_2dint(&render->map);
// 	if (render->player_image)
// 		mlx_delete_image(render->mlx, render->player_image);
// 	if (render->ray_image)
// 		mlx_delete_image(render->mlx, render->ray_image);
// 	if (render->mlx)
// 		mlx_terminate(render->mlx);
// 	free(render);
// }

int	main(int argc, char **argv)
{
	t_game		game;
	t_render	*render;

	(void)argc;
	(void)argv;

	render = init_render();
	if (implement_parsing(&game, render, argc, argv) == 0)
		return (1);
	game.render = render;
	// printf("y: %f\n",game.render->player_y);
	// printf("x: %f\n",game.render->player_x);
	// printf("x: %f\n",game.render->player_angle);
	mlx_start(&game);
	mlx_key_hook(render->mlx, &key_handler, &game);
	//mlx_loop_hook(render->mlx, &draw_rays, &game);
	mlx_loop_hook(render->mlx, &draw_player, render);
	mlx_loop(render->mlx);
	mlx_terminate(render->mlx);
	free_game(&game);
	// free_render(render);
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
// 	render = init_render();
// 	mlx_start(render);
// 	mlx_key_hook(render->mlx, &key_handler, render);
// 	mlx_loop_hook(render->mlx, &draw_player, render);
// 	mlx_loop(render->mlx);
// 	mlx_terminate(render->mlx);
// 	free(render);
// }