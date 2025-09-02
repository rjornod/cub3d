/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:22:10 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/14 17:22:04 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

static char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (dst == NULL || src == NULL || n == 0)
		return (dst);
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

static int	ft_count_substrings(const char *s, char c)
{
	int	i;
	int	count;
	int	in_substring;

	i = 0;
	count = 0;
	in_substring = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && !in_substring)
		{
			in_substring = 1;
			count++;
		}
		else if (s[i] == c)
			in_substring = 0;
		i++;
	}
	return (count);
}

static void	ft_free_arr(char **arr, int k)
{
	int	j;

	j = 0;
	while (j < k)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

static char	*ft_words(char const *s, char c, int *i)
{
	int		start;
	char	*word;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] != c && s[*i] != '\0')
		(*i)++;
	word = (char *)malloc((*i - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strncpy(word, &s[start], (size_t)(*i - start));
	word[*i - start] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		k;

	i = 0;
	k = 0;
	arr = (char **)malloc((ft_count_substrings(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (k < ft_count_substrings(s, c))
	{
		arr[k] = ft_words(s, c, &i);
		if (!arr[k])
		{
			ft_free_arr(arr, k);
			return (NULL);
		}
		k++;
	}
	arr[k] = NULL;
	return (arr);
}

// int main() {
// 	char input[] = "hello!zzzzzzzz";
// 	char delimiter = 'z';
// 	char** result = ft_split(input, delimiter);
// 	printf("Test  - Input: \"%s\", Delimiter: '%c'\n", input, delimiter);
// 	for (int i = 0; result[i] != NULL; i++) {
// 		printf("Substring %d: %s\n", i, result[i]);
// 		free(result[i]);  // Free each allocated substring
// 	}
// }
// 	free(result);  // Free the array of pointers
// }
// 	// Test case 2: Input with multiple delimiters in a row
// 	char input2[] = "split  this   string ";
// 	char delimiter2 = ' ';
// 	char** result2 = ft_strsplit(input2, delimiter2);

// 	printf("\nTest 2 - Input: \"%s\", Delimiter: '%c'\n", input2, delimiter2);
// 	for (int i = 0; result2[i] != NULL; i++) {
// 		printf("Substring %d: %s\n", i, result2[i]);
// 		free(result2[i]);  // Free each allocated substring
// 	}
// 	free(result2);  // Free the array of pointers

// 	// Test case 3: Input with a different delimiter (comma)
// 	char input3[] = "one,two,three,four";
// 	char delimiter3 = ',';
// 	char** result3 = ft_strsplit(input3, delimiter3);

// 	printf("\nTest 3 - Input: \"%s\", Delimiter: '%c'\n", input3, delimiter3);
// 	for (int i = 0; result3[i] != NULL; i++) {
// 		printf("Substring %d: %s\n", i, result3[i]);
// 		free(result3[i]);  // Free each allocated substring
// 	}
// 	free(result3);  // Free the array of pointers

// 	// Test case 4: Input with no delimiters (should return the whole string)
// 	char input4[] = "nodivider";
// 	char delimiter4 = ' ';
// 	char** result4 = ft_strsplit(input4, delimiter4);

// 	printf("\nTest 4 - Input: \"%s\", Delimiter: '%c'\n", input4, delimiter4);
// 	for (int i = 0; result4[i] != NULL; i++) {
// 		printf("Substring %d: %s\n", i, result4[i]);
// 		free(result4[i]);  // Free each allocated substring
// 	}
// 	free(result4);  // Free the array of pointers

// 	// Test case 5: Empty string input
// 	char input5[] = "";
// 	char delimiter5 = ' ';
// 	char** result5 = ft_strsplit(input5, delimiter5);

// 	printf("\nTest 5 - Input: \"%s\", Delimiter: '%c'\n", input5, delimiter5);
// 	if (result5 != NULL && result5[0] == NULL) {
// 		printf("Test 5 passed (empty input returns no substrings)\n");
// 	}
// 	free(result5);  // Free the array of pointers

// 	return 0;
// }