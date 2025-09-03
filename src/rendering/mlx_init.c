/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:51:12 by rojornod          #+#    #+#             */
/*   Updated: 2025/09/03 17:46:38 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_render	*init_render(void)
{
	t_render	*render;

	render = malloc(sizeof(t_render));
	if (!render)
		return (NULL);
	ft_memset(render, 0, sizeof(t_render));

	return (render);
}

void	mlx_start(t_game *game)
{
	printf("starting mlx\n");
	game->render->mlx = mlx_init(WIDTH, HEIGHT, "BEST GAME EVER", true);
	if (!game->render->mlx)
	{
		perror("Failed to initialize MLX42");
		exit(EXIT_FAILURE);
	}
	else
		printf("mlx started\n");
	mlx_key_hook(game->render->mlx, &key_handler, game->render);
	create_world(game);
	draw_player(game->render);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_putendl_fd("Goodbye", 1);
		mlx_close_window(game->render->mlx);
	}
	if (mlx_is_key_down(game->render->mlx, MLX_KEY_W))
	{
		//if (render->map[(int)render->pos_x + render->dir_x *])
		game->render->player_x += game->render->player_delta_x;
		game->render->player_y += game->render->player_delta_y;
	}
	if (mlx_is_key_down(game->render->mlx, MLX_KEY_S))
	{
		game->render->player_x -= game->render->player_delta_x;
		game->render->player_y -= game->render->player_delta_y;
	}
	if (mlx_is_key_down(game->render->mlx, MLX_KEY_D))
	{
		game->render->player_angle += 0.05;
		if (game->render->player_angle > 2 * PI)
			game->render->player_angle -= 2 * PI;
		game->render->player_delta_x = cos(game->render->player_angle) * 5;
		game->render->player_delta_y = sin(game->render->player_angle) * 5;
	}
	if (mlx_is_key_down(game->render->mlx, MLX_KEY_A))
	{
		game->render->player_angle -= 0.05;
		if (game->render->player_angle < 0)
			game->render->player_angle += 2 * PI;
		game->render->player_delta_x = cos(game->render->player_angle) * 5;
		game->render->player_delta_y = sin(game->render->player_angle) * 5;
	}
	printf("[%f]\n", game->render->player_angle);
	draw_rays(game);
	draw_player(game->render);
}

/*
	The deltas tell us wich direction the line goes, how steep the line is, how many steps are needed to draw the complete line
and which axis to use as the primary stepping direction (larger absoulte delta).
	float delta_x : horizontal distance form start to end
					if negative line goes right, if postive line goes left, if 0 just a vertical line
	float delta_y : vertical distance form start to end
					if positive line goes down, if negative line goes up, if 0 just a horizontal line
*/
// void	draw_line(mlx_image_t *img, float start_y, float start_x, float end_y,
// 	float end_x)
// {
// 	float	delta_x;
// 	float	delta_y;
	
// 	delta_x = end_x - start_x;
// 	delta_y = end_y - start_y;
	
// 	while ()
// 	{
		
// 	}
// }


