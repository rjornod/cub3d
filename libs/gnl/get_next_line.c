/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:55:32 by tignatov          #+#    #+#             */
/*   Updated: 2024/11/19 14:44:05 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *source, t_line *dest)
{
	char	*newl_ptr;

	newl_ptr = ft_strchr(source, '\n');
	if (newl_ptr)
		dest->len = newl_ptr - source + 1;
	else
		dest->len = ft_strlen(source);
	dest->content = (char *)malloc(dest->len + 1);
	if (!dest->content)
		return (free(dest->content), NULL);
	ft_strncpy(dest->content, source, dest->len);
	dest->content[dest->len] = '\0';
	return (dest->content);
}

static char	*join_lines(t_buffer *buffer, t_line *line)
{
	char	*tmp_line;
	char	*tmp_line2;

	if (line->content)
	{
		tmp_line = line->content;
		tmp_line2 = extract_line(buffer->buf, line);
		line->content = ft_strjoin(tmp_line, tmp_line2);
		if (!line->content)
			return (free(tmp_line2), free(tmp_line), NULL);
		free(tmp_line);
		free(tmp_line2);
	}
	else
	{
		line->content = extract_line(buffer->buf, line);
		if (!line->content)
			return (free(line->content), NULL);
	}
	return (line->content);
}

static char	*read_line(int fd, t_buffer *buffer, t_line *line)
{
	buffer->bytes_read = 1;
	while (buffer->bytes_read > 0)
	{
		buffer->bytes_read = read(fd, buffer->buf, BUFFER_SIZE);
		if (buffer->bytes_read == -1)
			return (NULL);
		if (buffer->bytes_read == 0)
			break ;
		buffer->buf[buffer->bytes_read] = '\0';
		line->content = join_lines(buffer, line);
		buffer->newl_ptr = ft_strchr(buffer->buf, '\n');
		if (buffer->newl_ptr)
		{
			if (*(buffer->newl_ptr + 1) != '\0')
			{
				ft_strncpy(buffer->rem, (buffer->newl_ptr + 1), BUFFER_SIZE);
				buffer->rem[BUFFER_SIZE] = '\0';
			}
			break ;
		}
	}
	return (line->content);
}

static int	get_remainder(t_buffer *buffer, t_line *line)
{
	buffer->newl_ptr = ft_strchr(buffer->rem, '\n');
	if (buffer->newl_ptr)
	{
		line->content = extract_line(buffer->rem, line);
		if (*(buffer->newl_ptr + 1) != '\0')
		{
			ft_strncpy(buffer->rem, (buffer->newl_ptr + 1), BUFFER_SIZE);
			buffer->rem[BUFFER_SIZE] = '\0';
		}
		else
			buffer->rem[0] = '\0';
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_buffer	buf = {"", "", 1, NULL};
	t_line			line;
	t_line			temp;

	line.content = NULL;
	line.len = 0;
	if (fd < 0)
		return (NULL);
	if (buf.rem[0] != '\0')
	{
		if (get_remainder(&buf, &line) == 1)
			return (line.content);
		else
		{
			line.content = ft_strdup(buf.rem);
			if (!line.content)
				return (NULL);
			buf.rem[0] = '\0';
		}
	}
	temp = line;
	line.content = read_line(fd, &buf, &temp);
	if (line.content)
		return (line.content);
	return (free(line.content), free(temp.content), NULL);
}
