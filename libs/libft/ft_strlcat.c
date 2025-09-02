/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:17:36 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/13 13:02:40 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while ((src[i] != '\0') && ((dst_len + i) < (dstsize - 1)))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int main(void)
// {
// 	//Test1
// 	char dst[50] = "Hello, ";
// 	const char* src = "World!";
// 	size_t result = ft_strlcat(dst, src, 50);
// 	printf("Test 1 result: %zu\n", result);
// 	printf("%s\n\n", dst);
// 	//Test2
// 	char dst1[10] = "Hello";
//     const char *src1 = "World";
//     size_t dstsize = 3;
//     size_t result1 = ft_strlcat(dst1, src1, dstsize);
//     printf("Test 2 result: %zu\n", result1);
//     printf("dst: \"%s\"\n", dst1);
// }