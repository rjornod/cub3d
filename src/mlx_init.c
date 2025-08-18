#include "../include/cub3d.h"

mlx_t	*mlx_start(mlx_t *mlx)
{
	mlx = mlx_init(1024, 1024, "BEST GAME EVER", true);
	if (!mlx)
	{
		perror("Failed to initialize MLX42");
		exit(EXIT_FAILURE);
	}
	return (mlx);
}
