/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 07:23:46 by tanja             #+#    #+#             */
/*   Updated: 2024/11/19 12:59:29 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	char	*fresh_str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	k = 0;
	fresh_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!(fresh_str))
		return (NULL);
	while (s1[i] != '\0')
	{
		fresh_str[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		fresh_str[i] = s2[k];
		k++;
		i++;
	}
	fresh_str[i] = '\0';
	return (fresh_str);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;

	cc = (char)c;
	while (*s)
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	slen;
	char	*new_str;

	slen = ft_strlen(s1);
	new_str = (char *)malloc((slen + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strncpy(new_str, s1, slen);
	new_str[slen] = '\0';
	return (new_str);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
