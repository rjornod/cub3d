/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:23:07 by tignatov          #+#    #+#             */
/*   Updated: 2025/09/01 14:49:17 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_input_file(char *file_name)
{
	int			fd;
	const char	*file_format = ft_strchr(file_name, '.');

	fd = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Error. Can't open the file.\n");
		return (false);
	}
	if (ft_strncmp(file_format, ".cub", 4) != 0)
		return (close(fd), printf("Error. Wrong format.\n"), false);
	close(fd);
	return (true);
}

bool	is_valid_input(int argc, char **argv)
{
	if (argc != 2)
		return (false);
	if (is_valid_input_file(argv[1]) == false)
		return (false);
	return (true);
}
