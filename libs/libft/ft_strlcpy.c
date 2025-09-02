/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 09:49:49 by tanja             #+#    #+#             */
/*   Updated: 2024/10/15 16:15:52 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// int main(void)
// {
// 	char dst[5];
// 	const char *src = "HelloWorld";
// 	size_t dstsize = sizeof(dst); 
// 	size_t result = ft_strlcpy(dst, src, dstsize);
// 	printf("Test 1: %zu\n", result);
// 	printf("Test 1: %s\n\n", dst);

// 	char dst1[20];
// 	const char *src1 = "Hello";
// 	size_t dstsize1 = sizeof(dst1); // dstsize = 20
// 	size_t result1 = ft_strlcpy(dst1, src1, dstsize1);
// 	printf("Test 2: %zu\n", result1);
// 	printf("Test 2: %s\n\n", dst1);

// 	char dst2[5];
// 	const char *src2 = "Hello";
// 	size_t result2 = ft_strlcpy(dst2, src2, 0);
// 	printf("Test 3: %zu\n", result2);
// 	printf("Test 3: %s\n\n", dst2);

// }