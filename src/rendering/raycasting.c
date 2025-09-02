#include "../../include/cub3d.h"

# define MAP_X 25
# define MAP_Y 14

void	init_r2(t_render *render)
{
	render->pos_x = 22;
	render->pos_y = 12;
	render->dir_x = -1;
	render->dir_y = 0;
	render->plane_x = 0;
	render->plane_y = 0.66;
	render->time = 0;
	render->old_time = 0;
	render->camera_x = 0;
	render->ray_dir_x = 0;
	render->ray_dir_y = 0;
}

static void calculate_step(t_render *render)
{
	if (render->ray_dir_x < 0)
	{
		render->step_x = -1;
		render->side_dist_x = (render->pos_x - render->map_x) * render->delta_dist_x;
	}
	else
	{
		render->step_y = 1;
		render->side_dist_x = (render->map_x + 1.0  - render->pos_x) * render->delta_dist_x;
	}
	if (render->ray_dir_y < 0)
	{
		render->step_x = -1;
		render->side_dist_y = (render->pos_y - render->map_y) * render->delta_dist_y;
	}
	else
	{
		render->step_y = 1;
		render->side_dist_y = (render->map_y + 1.0  - render->pos_y) * render->delta_dist_y;
	}
}

void	raycasting2(t_game *game)
{
	int			i;
	uint32_t	color;

	i = 0;
	while (i < WIDTH)
	{
		game->render->camera_x = 2 * i / (double)WIDTH - 1;
		game->render->ray_dir_x = game->render->dir_x + game->render->plane_x * game->render->camera_x;
		game->render->ray_dir_y = game->render->dir_y + game->render->plane_y * game->render->camera_x;
		game->render->map_x = (int)game->render->pos_x;
		game->render->map_y = (int)game->render->pos_y;
		if (game->render->ray_dir_x == 0)
			game->render->delta_dist_x = 1e30;
		else
			game->render->delta_dist_x = fabs(1.0 / game->render->ray_dir_x);
		if (game->render->ray_dir_y == 0)
			game->render->delta_dist_y = 1e30;
		else
			game->render->delta_dist_y = fabs(1.0 / game->render->ray_dir_y);
		game->render->hit = 0;
		calculate_step(game->render);
		//dda loop
		while (game->render->hit == 0)
		{
			if (game->render->side_dist_x < game->render->side_dist_y)
			{
				game->render->side_dist_x += game->render->delta_dist_x;
				game->render->map_x += game->render->step_x;
				game->render->side = 0;
			}
			else
			{
				game->render->side_dist_y += game->render->delta_dist_y;
				game->render->map_y += game->render->step_y;
				game->render->side = 1;			
			}
			if (game->render->map_x >= 0 && game->render->map_x < MAP_X && 
				game->render->map_y >= 0 && game->render->map_y < MAP_Y)
			{
				size_t map_index = game->render->map_y * game->map_info->max_len + game->render->map_x;
				if (map_index < (game->map_info->num_rows * game->map_info->max_len))
				{
					if (ft_strcmp(game->map[map_index], "1") == 0)
						game->render->hit = 1;
				}
			}
			else 
				game->render->hit = 1; //hit wall
			
		}
		if (game->render->side == 0)
				game->render->perp_wall_dist = (game->render->side_dist_x - game->render->delta_dist_x);
		else
			game->render->perp_wall_dist = (game->render->side_dist_y - game->render->delta_dist_y);
		game->render->line_height = (int)(HEIGHT / game->render->perp_wall_dist);

		game->render->draw_start = (-game->render->line_height / 2) + (HEIGHT / 2);
		if (game->render->draw_start < 0)
			game->render->draw_start = 0;
		game->render->draw_end = (game->render->line_height / 2) + (HEIGHT / 2);
		if (game->render->draw_end >= HEIGHT)
			game->render->draw_end = HEIGHT - 1;
		if (game->render->side == 1)
				color = WALL;
			else
				color = FLOOR;
		draw_col(game->render, i);
		i++;
	}
}

void draw_col(t_render *render, int x)
{
    // int col_x;
    // int wall_start;
    // int wall_end;
    // uint32_t wall_color;
    // int y;

    // // Calculate column position for 3D view (right half of screen)
    // col_x = (WIDTH / 2) + (render->ray * (WIDTH / 2) / 64);
    // wall_start = (HEIGHT / 2) - (render->line_height / 2);
    // wall_end = (HEIGHT / 2) + (render->line_height / 2);
    
    // // Choose wall color based on side for depth effect
    // if (render->side == 1)
    //     wall_color = WALL / 2;  // Darker for depth
    // else
    //     wall_color = WALL;
    
    // // Draw the vertical column
    // y = 0;
    // while (y < HEIGHT)
    // {
    //     if (y < wall_start)
    //         mlx_put_pixel(render->ray_image, col_x, y, 0x87CEEBFF); // Sky
    //     else if (y > wall_end)
    //         mlx_put_pixel(render->ray_image, col_x, y, 0x8B4513FF); // Floor
    //     else
    //         mlx_put_pixel(render->ray_image, col_x, y, wall_color); // Wall
    //     y++;
    // }
	 int y;
    uint32_t wall_color;
    
    if (render->side == 1)
        wall_color = WALL / 2;
    else
        wall_color = WALL;
    
    y = 0;
    while (y < HEIGHT)
    {
        if (y < render->draw_start)
            mlx_put_pixel(render->ray_image, x, y, 0x87CEEBFF); // Sky
        else if (y > render->draw_end)
            mlx_put_pixel(render->ray_image, x, y, 0x8B4513FF); // Floor
        else
            mlx_put_pixel(render->ray_image, x, y, wall_color); // Use calculated color
        y++;
    }
}