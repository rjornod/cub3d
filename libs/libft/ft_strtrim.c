/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:23:46 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/16 15:38:09 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	ft_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*fresh_str;
	int		i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	fresh_str = (char *)malloc((end - start + 2) * sizeof(char));
	if (!fresh_str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		fresh_str[i] = s1[start];
		i++;
		start++;
	}
	fresh_str[i] = '\0';
	return (fresh_str);
}

// int main()
// {
// 	char *result = ft_strtrim("  \t\t  ", " ");
// 	printf("Test 1: '%s'\n", result);
// 	printf("Test 1 expected: '%s'\n\n", "");
// 	free(result);

// 	char *result2 = ft_strtrim("hello", "x");
// 	printf("Test 2: %s\n", result2);
// 	printf("Test 2 expected: %s\n\n", "hello");
// 	free(result2);

// 	// char *result3 = ft_strtrim("xxhelloxx", "x");
// 	// printf("Test 3: %s\n", result3);
// 	// printf("Test 3 expected: %s\n\n", "hello");
// 	// free(result3);

// 	// char *result4 = ft_strtrim("hjh", "\0");
// 	// printf("Test 4: %s\n", result4);
// 	// printf("Test 4 expected: %s\n\n", "");
// 	// free(result4);

// 	// char *result5 = ft_strtrim("hello", "");
// 	// printf("Test 5: %s\n", result5);
// 	// printf("Test 1 expected: %s\n\n", "hello");
// 	// free(result5);

// 	// char *result7 = ft_strtrim("!!hello!!", "! ");
// 	// printf("Test 7: %s\n", result7);
// 	// printf("Test 7 expected: %s\n\n", "hello");
// 	// free(result7);

// 	return 0;
// }