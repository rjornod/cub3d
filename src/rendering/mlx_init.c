/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:51:12 by rojornod          #+#    #+#             */
/*   Updated: 2025/09/02 18:02:06 by rojornod         ###   ########.fr       */
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

	render->old_time = 0;
	render->move_speed = render->frame_time * 5.0;
	render->rotation_speed = render->frame_time * 3.0;
	return (render);
}

void	mlx_start(t_render *render)
{
	printf("starting mlx\n");
	render->mlx = mlx_init(WIDTH, HEIGHT, "BEST GAME EVER", true);
	if (!render->mlx)
	{
		perror("Failed to initialize MLX42");
		exit(EXIT_FAILURE);
	}
	else
		printf("mlx started\n");
	mlx_key_hook(render->mlx, &key_handler, render);
	create_world(render);
	draw_player(render);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	printf("Key handler called with key: %d\n", keydata.key);
	game = (t_game *)param;
	printf("Game pointer: %p\n", game);
	game->render->time = mlx_get_time();
	game->render->frame_time = game->render->time - game->render->old_time;
	game->render->old_time = game->render->time;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_putendl_fd("Goodbye", 1);
		mlx_close_window(game->render->mlx);
	}
	if (mlx_is_key_down(game->render->mlx, MLX_KEY_W))
	{
		game->render->new_pos_x = game->render->pos_x + game->render->dir_x * game->render->move_speed;
		game->render->new_pos_y = game->render->pos_y + game->render->dir_y * game->render->move_speed;
		if (game->map[(int)game->render->new_pos_y * MAP_X + (int)game->render->new_pos_x] == 0)
		{
			game->render->pos_x = game->render->new_pos_x;
			game->render->pos_y = game->render->new_pos_y;
		}
		// game->render->player_x += game->render->player_delta_x;
		// game->render->player_y += game->render->player_delta_y;
	}
	if (mlx_is_key_down(game->render->mlx, MLX_KEY_S))
	{
		game->render->new_pos_x = game->render->pos_x - game->render->dir_x * game->render->move_speed;
		game->render->new_pos_y = game->render->pos_y - game->render->dir_y * game->render->move_speed;
		if (game->map[(int)game->render->new_pos_y * MAP_X + (int)game->render->new_pos_x] == 0)
		{
			game->render->pos_x = game->render->new_pos_x;
			game->render->pos_y = game->render->new_pos_y;
		}
		
	}
	if (mlx_is_key_down(game->render->mlx, MLX_KEY_D))
	{
		game->render->old_dir_x = game->render->dir_x;
		game->render->dir_x = game->render->dir_x * cos(-game->render->rotation_speed) -  game->render->dir_y * sin(-game->render->rotation_speed);
		game->render->dir_y = game->render->old_dir_y * sin(-game->render->rotation_speed) + game->render->dir_y * cos(-game->render->rotation_speed);
		game->render->old_plane_x = game->render->plane_x;
		game->render->plane_x = game->render->plane_x * cos(-game->render->rotation_speed) - game->render->plane_y * sin(-game->render->rotation_speed);
		game->render->plane_y = game->render->old_plane_x * sin(-game->render->rotation_speed) + game->render->plane_y * cos(-game->render->rotation_speed);
		// game->render->player_angle += 0.05;
		// if (game->render->player_angle > 2 * PI)
		// 	game->render->player_angle -= 2 * PI;
		// game->render->player_delta_x = cos(game->render->player_angle) * 5;
		// game->render->player_delta_y = sin(game->render->player_angle) * 5;
	}
	if (mlx_is_key_down(game->render->mlx, MLX_KEY_A))
	{
		game->render->old_dir_x = game->render->dir_x;
		game->render->dir_x = game->render->dir_x * cos(game->render->rotation_speed) -  game->render->dir_y * sin(game->render->rotation_speed);
		game->render->dir_y = game->render->old_dir_y * sin(game->render->rotation_speed) + game->render->dir_y * cos(game->render->rotation_speed);
		game->render->old_plane_x = game->render->plane_x;
		game->render->plane_x = game->render->plane_x * cos(game->render->rotation_speed) - game->render->plane_y * sin(game->render->rotation_speed);
		game->render->plane_y = game->render->old_plane_x * sin(game->render->rotation_speed) + game->render->plane_y * cos(game->render->rotation_speed);
		// game->render->player_angle -= 0.05;
		// if (game->render->player_angle < 0)
		// 	game->render->player_angle += 2 * PI;
		// game->render->player_delta_x = cos(game->render->player_angle) * 5;
		// game->render->player_delta_y = sin(game->render->player_angle) * 5;
	}
	//draw_rays(game->render);
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


