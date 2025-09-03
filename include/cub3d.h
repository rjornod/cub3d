#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX/include/MLX42/MLX42.h"
# include "../libs/gnl/get_next_line.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define DR 0.0174533 //one degree in radians, used to seperate each ray by 1 degree
# define WIDTH 1920
# define HEIGHT 1080
# define PLAYER_COLOR 0xFF0000FF
# define WALL 0xFFFFFFFF
# define FLOOR 0x00FFFFFF
# define EMPTY 0x00000000
# define PI 3.1415926535
# define P2 PI / 2
# define P3 3 * PI / 2

enum					keys_texture
{
	KEY_NO,
	KEY_SO,
	KEY_WE,
	KEY_EA,
	NUM_KEYS1
};

enum					player_chars
{
	KEY_N,
	KEY_S,
	KEY_W,
	KEY_E,
};

enum					keys_colors
{
	KEY_F,
	KEY_C,
	NUM_KEYS2
};

typedef struct s_render
{
	mlx_t				*mlx;
	mlx_image_t			*player_image;
	mlx_image_t			*ray_image;
	float				player_x;
	float				player_y;
	float				player_delta_x;
	float				player_delta_y;
	float				player_angle;
	float				ray_angle;
	float				ray_y;
	float				ray_x;
	float				h_distance;
	float				v_distance;
	float				horizontal_ray_x_pos; //horizontal ray's x positions
	float				horizontal_ray_y_pos; //horizontal ray's y positions
	float				vertical_ray_x_pos; //vertical ray's x positions
	float				vertical_ray_y_pos; //vertical ray's y positions
	float				line_height;
	float				line_offset;
	float				correct_distance;
	float				fov;
	int					ray;
	float				y_offset;
	float				x_offset;
	int 				dof;
	float				final_dist;
	int					m_x;
	int					m_y;
	int					mp;
}						t_render;

typedef struct s_texture
{
	char				*n_text;
	char				*s_text;
	char				*w_text;
	char				*e_text;
}						t_texture;

typedef struct s_color
{
	char				*f_color;
	char				*c_color;
	unsigned long		f_rgb;
	unsigned long		c_rgb;
}						t_color;

typedef struct s_map
{
	size_t				max_len;
	size_t				num_rows;
	char				player_letter;
	int					player_flag;
}						t_map;

typedef struct s_game
{
	char				**initial_file;
	char				**map;
	struct s_texture	*textures;
	struct s_color		*colors;
	struct s_render		*render;
	struct s_map		map_info;
}						t_game;

/*parsing*/

bool					is_valid_input(int argc, char **argv);
bool					is_valid_input_file(char *file_name);
int						parse_map(t_game *game, char *file);
bool					is_map_last(char **map);
int						find_textures(char **map);
bool					no_invalid_input(char *line, int in_map);
int						count_num_lines(char *file);
int						parse_file(char **file);
bool					is_valid_color(char *file);
bool					is_valid_color_line(char *line);
bool					is_color(char *line);
bool					is_texture(char *line);
bool					is_color(char *line);
t_map					find_map_size(char **file);
int						validate_map(t_game *game, char **initial_file,
							t_render *render);
char					**map_for_valid(char **file, t_map *map_dim);
int						ft_dfs_inside(char **map, size_t row, size_t col,
							t_map *map_dim);
bool	map_chars_valid(t_game *game, char **map, t_map *map_for_pos);
void					find_player_position(char **map, t_render *render,
							t_map *map_for_pos);
int						init_game_parsing(t_game *game);
int						implement_parsing(t_game *game, t_render *render, 
							int argc, char **argv);
/*utils*/
void					free_2darray_partial(char **arr, int num);
void					free_2darray(char **arr);
void					print_2d_array(char **arr);
int						ft_count_substrings(const char *s, char c);
void					free_2dint_partial(int **arr, int num);
void					free_2dint(int **arr);
int						parse_colors(t_game *game);
void					copy_string(char *checking_char, char *color);
int						parse_textures(t_game *game);
int						malloc_map(char **map, t_map *map_dim);
void					free_game(t_game *game);
int						init_game_parsing(t_game *game);

/* ----mlx---- */
t_render				*init_render(void);
void					mlx_start(t_game *game);
void					draw_player(void *param);
void					key_handler(mlx_key_data_t keydata, void *param);
void					create_world(void *param);
void					put_tile(mlx_image_t *image, int start_x, int start_y,
							int size, uint32_t color);
void					draw_rays(void *param);
int						draw_line(t_render *render, int begin_x, int begin_y, int end_x, int end_y);
void					draw_col(t_render *render);
/* ----render utils---- */
float					distance(float ax, float ay, float bx, float by,
							float ang);

#endif