/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:17:01 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/13 13:09:01 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

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

// int main(void)
// {
// 	char* result;

// 	result = ft_strjoin("Hello, ", "World!");
// 	if (result)
// 	{
// 		printf("Test case 1: Expected: 'Hello, World!', Got: '%s'\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Test case 1: Memory allocation failed.\n");
// 	}

// 	result = ft_strjoin("", "World!");
// 	if (result)
// 	{
// 		printf("Test case 2: Expected: 'World!', Got: '%s'\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Test case 2: Memory allocation failed.\n");
// 	}
// }