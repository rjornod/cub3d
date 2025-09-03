#include "cub3d.h"

static void check_horizontal_lines(t_game *game, float a_tan)
{
	game->render->horizontal_ray_x_pos = game->render->player_x;
	game->render->horizontal_ray_y_pos = game->render->player_y;
	if (game->render->ray_angle > PI) // looking up
	{
		game->render->ray_y = (((int)game->render->player_y / 64) * 64) - 0.0001;
		game->render->ray_x = (game->render->player_y - game->render->ray_y) * a_tan + game->render->player_x;
		game->render->y_offset = -64; 
		game->render->x_offset = game->render->y_offset * a_tan; 
	}
	else if (game->render->ray_angle < PI) // looking down
	{
		game->render->ray_y = (((int)game->render->player_y / 64) * 64) + 64;
		game->render->ray_x = (game->render->player_y - game->render->ray_y) * a_tan + game->render->player_x;
		game->render->y_offset = 64; 
		game->render->x_offset = game->render->y_offset * a_tan; 
	}
	else if (game->render->ray_angle == 0 || game->render->ray_angle == PI) // looking straight left or right
	{
		game->render->ray_x = game->render->player_x;
		game->render->ray_y = game->render->player_y;
		game->render->dof = 8;
	}
	while (game->render->dof < 8)
	{
		game->render->m_x = (int)(game->render->ray_x) / 64;
		game->render->m_y = (int)(game->render->ray_y) / 64;
		if (game->render->m_x >= 0 && game->render->m_x < (int)game->map_info.max_len && 
            game->render->m_y >= 0 && game->render->m_y < (int)game->map_info.num_rows)
		{
			if (game->map[game->render->m_y][game->render->m_x] == '1')
			{
				game->render->horizontal_ray_x_pos = game->render->ray_x;
				game->render->horizontal_ray_y_pos = game->render->ray_y;
				game->render->h_distance = distance(game->render->player_x, game->render->player_y, game->render->horizontal_ray_x_pos, game->render->horizontal_ray_y_pos, game->render->ray_angle);
				game->render->dof = 8;
			}
			else
			{
				game->render->ray_x += game->render->x_offset;
				game->render->ray_y += game->render->y_offset;
				game->render->dof += 1;
			}
		}
		else
			game->render->dof = 8;
	}
	//draw_line(render, (int)render->player_x, (int)render->player_y, (int)render->ray_x, (int)render->ray_y);
		
}

static void	check_vertical_lines(t_game *game, float n_tan)
{
	game->render->vertical_ray_x_pos = game->render->player_x;
	game->render->vertical_ray_y_pos = game->render->player_y;
	if (game->render->ray_angle > P2 && game->render->ray_angle < P3) // looking left
	{
		game->render->ray_x = ((game->render->player_x / 64) * 64) - 0.0001;
		game->render->ray_y = (game->render->player_x - game->render->ray_x) * n_tan + game->render->player_y;
		game->render->x_offset = -64;
		game->render->y_offset = game->render->x_offset * n_tan; 
	}
	else if (game->render->ray_angle < P2 || game->render->ray_angle > P3) // looking right
	{
		game->render->ray_x = ((game->render->player_x / 64) * 64) + 64;
		game->render->ray_y = (game->render->player_x - game->render->ray_x) * n_tan + game->render->player_y;
		game->render->x_offset = 64; 
		game->render->y_offset = game->render->x_offset * n_tan; 
	}
	else if (game->render->ray_angle == P2 || game->render->ray_angle == P3) // looking straight up or down
	{
		game->render->ray_x = game->render->player_x;
		game->render->ray_y = game->render->player_y;
		game->render->dof = 8;
	}
	while (game->render->dof < 8)
	{
		game->render->m_x = (int)(game->render->ray_x) / 64;
		game->render->m_y = (int)(game->render->ray_y) / 64;
		 if (game->render->m_x >= 0 && game->render->m_x < (int)game->map_info.max_len && 
            game->render->m_y >= 0 && game->render->m_y < (int)game->map_info.num_rows)
		{
			if (game->map[game->render->m_y][game->render->m_x] == '1')
			{
				game->render->vertical_ray_x_pos = game->render->ray_x;
				game->render->vertical_ray_y_pos = game->render->ray_y;
				game->render->v_distance = distance(game->render->player_x, game->render->player_y, game->render->vertical_ray_x_pos, game->render->vertical_ray_y_pos, game->render->ray_angle);
				game->render->dof = 8;
			}
			else //next line
			{
				game->render->ray_x += game->render->x_offset;
				game->render->ray_y += game->render->y_offset;
				game->render->dof += 1;
			}
		}
		else
			game->render->dof = 8;
	}
}

// function that will return the distance between the player and the rays end point
float	distance(float ax, float ay, float bx, float by, float ang)
{
	(void)ang;
	return (sqrt((bx-ax) * (bx-ax) + (by-ay) * (by-ay)));
}

void	draw_rays(void  *param)
{
	float		a_tan;
	float		n_tan;
	float		ray_angle_increment;
	t_game	*game;

	game = (t_game *)param;
 	if (!game || !game->render->ray_image || !game->render->ray_image->pixels)
        return;
	ft_memset(game->render->ray_image->pixels, 0, WIDTH * HEIGHT * sizeof(int32_t));
	//calculate the field of view in radians (60 degrees = PI/3)
	game->render->fov = PI / 3;
	ray_angle_increment = game->render->fov / (WIDTH / 2); // half width for right side 3d view
	
	game->render->ray_angle = game->render->player_angle + (game->render->fov / 2);
	//angle normalization
	if (game->render->ray_angle < 0)
		game->render->ray_angle += 2 * PI;
	else if (game->render->ray_angle > 2 * PI)
		game->render->ray_angle -= 2 * PI;
	game->render->ray = 0;
	printf("----------------------------------\n");
	while (game->render->ray < (WIDTH / 2)) // rays for right half only
	{
		game->render->h_distance = 1000000;
		game->render->v_distance = 1000000;
		game->render->dof = 0;
		//angle normalization
		if (game->render->ray_angle < 0)
			game->render->ray_angle += 2 * PI;
		if (game->render->ray_angle > 2 * PI)
			game->render->ray_angle -= 2 * PI;
		//------------------------------------
		n_tan = -tan(game->render->ray_angle);
		a_tan = -1 / tan(game->render->ray_angle);
		game->render->dof = 0;
		check_horizontal_lines(game, a_tan);
		game->render->dof = 0;
		check_vertical_lines(game, n_tan);
		if (game->render->v_distance < game->render->h_distance)
		{
			game->render->ray_x = game->render->vertical_ray_x_pos;
			game->render->ray_y = game->render->vertical_ray_y_pos;
			game->render->final_dist = game->render->v_distance;
		}
		if (game->render->h_distance < game->render->v_distance)
		{
			game->render->ray_x = game->render->horizontal_ray_x_pos;
			game->render->ray_y = game->render->horizontal_ray_y_pos;
			game->render->final_dist = game->render->h_distance;
		}
		game->render->correct_distance = game->render->final_dist * cos(game->render->ray_angle - game->render->player_angle); //fisheye correction
		if (game->render->correct_distance < 1.0) //prevent division by zero 
			game->render->correct_distance = 1.0;
		game->render->line_height = (64 * HEIGHT) / game->render->correct_distance; //calculate wall height based on the distance
		// cap the line height
		if (game->render->line_height > HEIGHT)
			game->render->line_height = HEIGHT;
		if (game->render->line_height < 1)
			game->render->line_height = 1;
		
		// Only draw every 8th ray to avoid cluttering the 2D view
	
		if (game->render->ray % 8 == 0)
			draw_line(game->render, (int)game->render->player_x, (int)game->render->player_y, (int)game->render->ray_x, (int)game->render->ray_y);
		
		draw_col(game->render);
		//line offset
		game->render->line_offset = (HEIGHT / 2) - (game->render->line_height / 2);
		game->render->ray++;
		game->render->ray_angle -= ray_angle_increment;
		
	}
	printf("----------------------------------\n");
}

static int	determine_steps(float delta_x, float delta_y)
{
	if (fabs(delta_x) > fabs(delta_y))
		return ((int)fabs(delta_x));
	else
		return ((int)fabs(delta_y));
}

int	draw_line(t_render *render, int begin_x, int begin_y, int end_x, int end_y)
{
	float	delta_x;
	float	delta_y;
	float	current_x;
	float	current_y;
	float	step_x;
	float	step_y;
	int		steps;
	int		i;

	i = 0;
	delta_y = end_y - begin_y;
	delta_x = end_x - begin_x;
	steps = determine_steps(delta_x, delta_y);
	//printf("steps [%d\n", steps);
	step_x = delta_x / steps;
	step_y = delta_y / steps;
	current_x = begin_x;
	current_y = begin_y;
	while (i <= steps)
	{
		//only drawing rays on right half of the window
        if ((int)current_x >= 0 && (int)current_x < (WIDTH / 2) && 
            (int)current_y >= 0 && (int)current_y < HEIGHT)
            mlx_put_pixel(render->ray_image, (int)current_x, (int)current_y, 0xFF0000FF);
        current_x += step_x;
        current_y += step_y;
		i++;
	}
	printf("[%f]\n", render->ray_angle);
	
	return (0);
}

void	draw_col(t_render *render)
{
	int	col_x;
	int	wall_start;
	int wall_end;
	int y;

	y = 0;
	// Draw 3D view on the right half of the screen
	col_x = (WIDTH / 2) + render->ray;
	if (col_x >= WIDTH)
		return ;
	wall_start = (HEIGHT / 2) - (render->line_height / 2);
	wall_end = (HEIGHT / 2) + (render->line_height / 2);
	while (y < HEIGHT)
	{
		if (y < wall_start)
			 mlx_put_pixel(render->ray_image, col_x, y, 0x87CEEBFF);
		else if (y > wall_end)
			mlx_put_pixel(render->ray_image, col_x, y, 0x8B4513FF);
		else
			mlx_put_pixel(render->ray_image, col_x, y, WALL);
		y++;
	}
}
