/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanja <tanja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:23:26 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/11 20:41:56 by tanja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*fresh_str;
	size_t	slen;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	i = 0;
	fresh_str = (char *)malloc(len * sizeof(char) + 1);
	if (!fresh_str)
		return (NULL);
	while (i < len)
	{
		fresh_str[i] = s[start];
		i++;
		start++;
	}
	fresh_str[i] = '\0';
	return (fresh_str);
}

// int main(void)
// {
// 	char* result;
// 	const char* str = "Hello, World!";
// 	unsigned int start;
// 	size_t len;

// 	start = 7;
// 	len = 5;
// 	result = ft_substr(str, start, len);
// 	if (result)
// 	{
// 		printf("Expected: 'World', Got: '%s'\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed.\n");
// 	}
// 	return (0);
// }