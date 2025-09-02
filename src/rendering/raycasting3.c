#include "cub3d.h"

// static void check_horizontal_lines(t_render *render, float a_tan)
// {
// 	render->horizontal_ray_x_pos = render->player_x;
// 	render->horizontal_ray_y_pos = render->player_y;
// 	printf("Player: (%.1f, %.1f) Angle: %.2f degrees\n", 
//        render->player_x, render->player_y, 
//        render->player_angle * 180.0 / PI);
// 	printf("Ray %d: Angle %.2f degrees -> Wall at (%.1f, %.1f)\n",
//        render->ray, render->ray_angle * 180.0 / PI,
//        render->ray_x, render->ray_y);
// 	if (render->ray_angle > PI) // looking up
// 	{
// 		render->ray_y = (((int)render->player_y / 64) * 64) - 0.0001;
// 		render->ray_x = (render->player_y - render->ray_y) * a_tan + render->player_x;
// 		render->y_offset = -64; 
// 		render->x_offset = render->y_offset * a_tan; 
// 	}
// 	else if (render->ray_angle < PI) // looking down
// 	{
// 		render->ray_y = (((int)render->player_y / 64) * 64) + 64;
// 		render->ray_x = (render->player_y - render->ray_y) * a_tan + render->player_x;
// 		render->y_offset = 64; 
// 		render->x_offset = render->y_offset * a_tan; 
// 	}
// 	else if (render->ray_angle == 0 || render->ray_angle == PI) // looking straight left or right
// 	{
// 		render->ray_x = render->player_x;
// 		render->ray_y = render->player_y;
// 		render->dof = 8;
// 	}
// 	while (render->dof < 8)
// 	{
// 		render->m_x = (int)(render->ray_x) / 64;
// 		render->m_y = (int)(render->ray_y) / 64;
// 		if (render->m_x >= 0 && render->m_x < 25 && render->m_y >= 0 && render->m_y < 14)
// 		{
// 			render->mp = render->m_y * 25 + render->m_x;
// 			if (render->map[render->mp] == 1)
// 			{
// 				render->horizontal_ray_x_pos = render->ray_x;
// 				render->horizontal_ray_y_pos = render->ray_y;
// 				render->h_distance = distance(render->player_x, render->player_y, render->horizontal_ray_x_pos, render->horizontal_ray_y_pos, render->ray_angle);
// 				render->dof = 8;
// 			}
// 			else
// 			{
// 				render->ray_x += render->x_offset;
// 				render->ray_y += render->y_offset;
// 				render->dof += 1;
// 			}
// 		}
// 		else
// 			render->dof = 8;
// 	}
// 	//draw_line(render, (int)render->player_x, (int)render->player_y, (int)render->ray_x, (int)render->ray_y);
		
// }

// static void	check_vertical_lines(t_render *render, float n_tan)
// {
// 	render->vertical_ray_x_pos = render->player_x;
// 	render->vertical_ray_y_pos = render->player_y;
// 	if (render->ray_angle > P2 && render->ray_angle < P3) // looking left
// 	{
// 		render->ray_x = (((int)render->player_x / 64) * 64) - 0.0001;
// 		render->ray_y = (render->player_x - render->ray_x) * n_tan + render->player_y;
// 		render->x_offset = -64;
// 		render->y_offset = render->x_offset * n_tan; 
// 	}
// 	else if (render->ray_angle < P2 || render->ray_angle > P3) // looking right
// 	{
// 		render->ray_x = (((int)render->player_x / 64) * 64) + 64;
// 		render->ray_y = (render->player_x - render->ray_x) * n_tan + render->player_y;
// 		render->x_offset = 64; 
// 		render->y_offset = render->x_offset * n_tan; 
// 	}
// 	else if (render->ray_angle == P2 || render->ray_angle == P3) // looking straight up or down
// 	{
// 		render->ray_x = render->player_x;
// 		render->ray_y = render->player_y;
// 		render->dof = 8;
// 	}
// 	while (render->dof < 8)
// 	{
// 		render->m_x = (int)(render->ray_x) / 64;
// 		render->m_y = (int)(render->ray_y) / 64;
// 		if (render->m_x >= 0 && render->m_x < 25 && render->m_y >= 0 && render->m_y < 14)
// 		{
// 			render->mp = render->m_y * 25 + render->m_x;
// 			if (render->map[render->mp] == 1) //hit wall
// 			{
// 				render->vertical_ray_x_pos = render->ray_x;
// 				render->vertical_ray_y_pos = render->ray_y;
// 				render->v_distance = distance(render->player_x, render->player_y, render->vertical_ray_x_pos, render->vertical_ray_y_pos, render->ray_angle);
// 				render->dof = 8;
// 			}
// 			else //next line
// 			{
// 				render->ray_x += render->x_offset;
// 				render->ray_y += render->y_offset;
// 				render->dof += 1;
// 			}
// 		}
// 		else
// 			render->dof = 8;
// 	}
// }

// // function that will return the distance between the player and the rays end point
// float	distance(float ax, float ay, float bx, float by, float ang)
// {
// 	(void)ang;
// 	return (sqrt((bx-ax) * (bx-ax) + (by-ay) * (by-ay)));
// }

// void	draw_rays(t_render *render)
// {
// 	float	a_tan;
// 	float	n_tan;

// 	ft_memset(render->ray_image->pixels, 0, WIDTH * HEIGHT * sizeof(int32_t));
// 	render->ray_angle = render->player_angle - DR * 30;
// 	if (render->ray_angle < 0)
// 		render->ray_angle += 2 * PI;
// 	else if (render->ray_angle > 2 * PI)
// 		render->ray_angle -= 2 * PI;
// 	render->ray = 0;
// 	while (render->ray < 64) //number of rays being cast
// 	{
// 		render->h_distance = 1000000;
// 		render->v_distance = 1000000;
// 		render->dof = 0;
// 		render->ray_angle += DR;
// 		if (render->ray_angle < 0)
// 			render->ray_angle += 2 * PI;
// 		if (render->ray_angle > 2 * PI)
// 			render->ray_angle -= 2 * PI;
// 		n_tan = -tan(render->ray_angle);
// 		a_tan = -1 / tan(render->ray_angle);
// 		render->dof = 0;
// 		check_horizontal_lines(render, a_tan);
// 		render->dof = 0;
// 		check_vertical_lines(render, n_tan);
// 		if (render->v_distance < render->h_distance)
// 		{
// 			render->ray_x = render->vertical_ray_x_pos;
// 			render->ray_y = render->vertical_ray_y_pos;
// 			render->final_dist = render->v_distance;
// 		}
// 		if (render->h_distance < render->v_distance)
// 		{
// 			render->ray_x = render->horizontal_ray_x_pos;
// 			render->ray_y = render->horizontal_ray_y_pos;
// 			render->final_dist = render->h_distance;
// 		}
		
// 		draw_line(render, (int)render->player_x, (int)render->player_y, (int)render->ray_x, (int)render->ray_y);
// 		draw_col(render);
// 		//draw 3d walls
// 		render->line_height = (360 * WIDTH) / render->final_dist;
// 		//line height
// 		if (render->line_height > WIDTH)
// 			render->line_height = 320;
// 		//line offset
// 		render->line_offset = 160 - render->line_height / 2;
// 		render->ray++;
		
// 	}
// }

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
	step_x = delta_x / steps;
	step_y = delta_y / steps;
	current_x = begin_x;
	current_y = begin_y;
	while (i <= steps)
	{
        if ((int)current_x >= 0 && (int)current_x < WIDTH && 
            (int)current_y >= 0 && (int)current_y < HEIGHT)
            mlx_put_pixel(render->ray_image, (int)current_x, (int)current_y, 0xFF0000FF);
        current_x += step_x;
        current_y += step_y;
		i++;
	}
	return (0);
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
    
    y = 0;
    while (y < HEIGHT)
    {
        if (y < render->draw_start)
            mlx_put_pixel(render->ray_image, x, y, 0x87CEEBFF); // Sky
        else if (y > render->draw_end)
            mlx_put_pixel(render->ray_image, x, y, 0x8B4513FF); // Floor
        else
            mlx_put_pixel(render->ray_image, x, y, WALL); // Wall
        y++;
    }
}
