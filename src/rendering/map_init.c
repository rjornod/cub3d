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
	if (!game || !game->map) {
		printf("ERROR: Invalid render or render->map is NULL\n");
		return;
	}
	uint32_t color;

	int	x = 0;
	int map_s = 64;
	int y = 0;
	int	xo = 0;
	int yo = 0;

	printf("render->map address: %p\n", game->map);
	if (!game->map) 
	{
   		 printf("ERROR: render->map is NULL!\n");
    	return;
	}
	// ft_memcpy(game->map, map, sizeof(map));
	
	tile = mlx_new_image(game->render->mlx, WIDTH, HEIGHT);
    if (!tile)
		return;
	ft_memset(tile->pixels, 0, WIDTH * HEIGHT * sizeof(int32_t));
	while (y < (int)game->map_info->max_len)
	{
		x = 0; 
		while (x < MAP_X)
		{
			printf("y: [%d]\nmap_x: [%zu]\nx: [%d]\n", y, game->map_info->max_len, x);
			if (ft_strcmp(game->map[y * game->map_info->num_rows + x], "2") == 0)
			{
				printf("x: [%d]\n", x);
				printf("y: [%d]\n", y);
				game->render->pos_x = (float)(x * map_s) + (map_s / 2);
				game->render->pos_y = (float)(y * map_s) + (map_s / 2);
				//render->player_angle = 0.0f;
			}
			printf("passed\n");
			if (ft_strcmp(game->map[y * MAP_X + x], "1") == 0)
				color = WALL;
			else
				color = FLOOR;
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
	// render->player_delta_x = cos(render->player_angle) * 5;
	// render->player_delta_y = sin(render->player_angle) * 5;
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
	pixel_x = render->pos_x;
	pixel_y = render->pos_y;
	printf("player x: [%f]\n", render->pos_x);
	printf("player y: [%f]\n", render->pos_y);
	put_tile(render->player_image, (int)pixel_x - 5, (int)pixel_y - 5, 10 , PLAYER_COLOR);
	
}