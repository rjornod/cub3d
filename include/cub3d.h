#ifndef CUB3D_H
#define CUB3D_H


# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libs/MLX/include/MLX42/MLX42.h"
# include <fcntl.h>
# include "../libs//libft/libft.h"

typedef struct s_texture
{
    char    *n_text;
    char    *s_text;
    char    *w_text;
    char    *e_text;
} t_texture;

typedef struct s_color
{
    char    *f_color;
    char    *c_color;
} t_color;

typedef struct s_game
{
    char    **map;
    struct s_texture    *textures;
    struct s_color      *colors;
} t_game;

mlx_t	*mlx_start(mlx_t *mlx);

#endif