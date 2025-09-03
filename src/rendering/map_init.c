#include "cub3d.h"

//player_delta_x and y represent the movement vector of the player, the direction and speed the player moves when pressing movement keyes.
//x is horizontal forward direction
//y is vertical forward direction
//cos(player_angle) * 5: speed is 5. player moves 5 pixels per keypress
void create_world(void *param)
{
	mlx_image_t	* tile;
	t_game	*game;

	game = (t_game *)param;
	if (!game->render) {
		printf("ERROR: Invalid game->render or game->map is NULL\n");
		return ;
	}
	uint32_t color;

	int	x = 0;
	int map_s = 64;
	int y = 0;
	int	xo = 0;
	int yo = 0;
	// int map_x = 25;
	// int map_y = 14;
	// int map[] = {
	// 	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	// 	1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	// 	1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	// 	1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	// 	1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1,
	// 	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1,
	// 	1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
	// 	1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1,
	// 	1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
	// 	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1,
	// 	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1,
	// 	1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
	// 	1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1,
	// 	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	// };
	//  int map[] = {
	// 	1,1,1,1,1,1,1,1,
	// 	1,0,0,0,0,0,0,1,
	// 	1,0,0,0,0,0,0,1,
	// 	1,0,0,0,0,0,0,1,
	// 	1,0,0,0,0,0,0,1,
	// 	1,0,0,0,0,0,0,1,
	// 	1,0,0,0,0,0,0,1,
	// 	1,1,1,1,1,1,1,1
	//  }
	printf("render->map address: %p\n", game->map);
	if (!game->map) 
	{
   		 printf("ERROR: render->map is NULL!\n");
    	return;
	}
	//ft_memcpy(game->render->map, map, sizeof(map));
	
	tile = mlx_new_image(game->render->mlx, WIDTH, HEIGHT);
    if (!tile)
		return;
	ft_memset(tile->pixels, 0, WIDTH * HEIGHT * sizeof(int32_t));
	print_2d_array(game->map);
	while (y < (int)game->map_info.num_rows)
	{
		x = 0; 
		while (x < (int)game->map_info.max_len)
		{
			// if (ft_strcmp(game->map[y * (int)game->map_info.num_rows + x], "N") == 0)
			// {
			// 	game->render->player_x = (float)(x * map_s) + (map_s / 2);
			// 	game->render->player_y = (float)(y * map_s) + (map_s / 2);
			// 	printf("[%f] [%f]", game->render->player_x, game->render->player_y);
			// 	game->render->player_angle = 0.0f;
			// }
			if (game->map[y][x] == '1')
			{
				//printf("x[%d] y[%d]\n", x, y);
				color = WALL;
			}
			else if (game->map[y][x] == '0' || game->map[y][x] == 'N' || game->map[y][x] == 'S' 
				|| game->map[y][x] == 'W' || game->map[y][x] == 'E')
			{
				//printf("x[%d] y[%d]\n", x, y);
				color = FLOOR;
			}
			else
			{
				//printf("x[%d] y[%d]\n", x, y); 
				color = EMPTY;
			}
			xo = x * map_s;
			yo = y * map_s;
			if (xo < (WIDTH / 2) && yo < HEIGHT)
				put_tile(tile, xo, yo, map_s, color);
			x++;
		}
		y++;
	}
	game->render->ray_image = mlx_new_image(game->render->mlx, WIDTH, HEIGHT);
	if (!game->render->ray_image)
		return ;
	ft_memset(game->render->ray_image->pixels, 0,
		WIDTH * HEIGHT * sizeof(int32_t));
	mlx_image_to_window(game->render->mlx, tile, 0, 0);
	mlx_image_to_window(game->render->mlx, game->render->ray_image, 0, 0);
	game->render->player_delta_x = cos(game->render->player_angle) * 5;
	game->render->player_delta_y = sin(game->render->player_angle) * 5;
}

void	put_tile(mlx_image_t *image, int start_x, int start_y, int size, uint32_t color)
{
	int	x;
	int y;

	y = start_y + 1;
	x = start_x + 1;
	while (y < start_y + size - 1)
	{
		x = start_x + 1;
		while (x < start_x + size -1)
		{
			if (x >= 0 && x < (int)image->width && y >= 0 && y < (int)image->height)
				mlx_put_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_player(void *param)
{
	t_render	*render;
	float		pixel_x;
	float		pixel_y;
	float		y;
	float		x;

	y = 0;
	x = 0;
	render = (t_render *)param;
	if (!render->player_image)
	{
		render->player_image = mlx_new_image(render->mlx, WIDTH, HEIGHT);
		if (mlx_image_to_window(render->mlx, render->player_image, 0,  0) < 0)
			return ;
	}
	
	ft_memset(render->player_image->pixels, 0,
		WIDTH * HEIGHT * sizeof(int32_t));
	pixel_x = render->player_x;
	pixel_y = render->player_y;
	put_tile(render->player_image, (int)pixel_x - 5, (int)pixel_y - 5, 10 , PLAYER_COLOR);
	
}
