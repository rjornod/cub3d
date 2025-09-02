/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 07:24:01 by tanja             #+#    #+#             */
/*   Updated: 2024/11/19 14:44:06 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# if BUFFER_SIZE <= 0
#  error BUFFER_SIZE needs to be bigger than 0
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_buffer
{
	char	buf[BUFFER_SIZE + 1];
	char	rem[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*newl_ptr;
}	t_buffer;

typedef struct s_line
{
	char	*content;
	size_t	len;
}	t_line;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strncpy(char *dst, const char *src, size_t n);

#endif