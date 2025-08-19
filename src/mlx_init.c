/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojornod <rojornod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:51:12 by rojornod          #+#    #+#             */
/*   Updated: 2025/08/19 17:18:10 by rojornod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(void *param)
{
	t_render	*render;
	float		pixel_x;
	float		pixel_y;

	render = (t_render *)param;
	if (!render->player_image)
	{
		render->player_image = mlx_new_image(render->mlx, WIDTH, HEIGHT);
		if (mlx_image_to_window(render->mlx, render->player_image, 0, 0) < 0)
			return ;
	}
	ft_memset(render->player_image->pixels, 0,
		WIDTH * HEIGHT * sizeof(int32_t));
	pixel_x = render->player_x;
	pixel_y = render->player_y;
	if (pixel_x >= 0 && pixel_x < WIDTH && pixel_y >= 0 && pixel_y < HEIGHT)
		mlx_put_pixel(render->player_image, (int)pixel_x,
			(int)pixel_y, PLAYER_COLOR);
}

t_render	*init_render(void)
{
	t_render	*render;

	render = malloc(sizeof(t_render));
	if (!render)
		return (NULL);
	ft_memset(render, 0, sizeof(t_render));
	return (render);
}

void	mlx_start(t_render *render)
{
	render->mlx = mlx_init(WIDTH, HEIGHT, "BEST GAME EVER", true);
	if (!render->mlx)
	{
		perror("Failed to initialize MLX42");
		exit(EXIT_FAILURE);
	}
	mlx_key_hook(render->mlx, &key_handler, render);
	draw_player(render);
}

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_render	*render;

	render = (t_render *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_putendl_fd("Goodbye", 1);
		mlx_close_window(render->mlx);
	}
	if (mlx_is_key_down(render->mlx, MLX_KEY_W))
		render->player_y -= MOVEMENT;
	if (mlx_is_key_down(render->mlx, MLX_KEY_S))
		render->player_y += MOVEMENT;
	if (mlx_is_key_down(render->mlx, MLX_KEY_D))
		render->player_x += MOVEMENT;
	if (mlx_is_key_down(render->mlx, MLX_KEY_A))
		render->player_x -= MOVEMENT;
	draw_player(render);
}

void create_world()
{
	mlx_image_t* wall;
	uint32_t	i;
	int	x;
	int y;
	int	xo;
	int yo;
	int map_x = 8;
	int map_y = 5;
	int map[] = {
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 0, 0, 0, 0, 1,
		1, 0, 1, 1, 0, 0, 1, 1,
		1, 0, 0, 0, 0, 1, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};
	while (i < wall->width; ++i)
	{
		uint32_t i = 0;
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}