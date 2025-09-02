/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:11:13 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/13 17:08:10 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}

// int main() {
// 	char src[] = "Hello, World!";
// 	char src2[] = "cat";
// 	char dst[20];

// 	ft_memcpy(dst, src, 14);
// 	printf("Test 1: %s\n", dst);

// 	ft_memcpy(dst, src, 0);
//     printf("Test 2: 0 bytes: %s\n", dst);

// 	ft_memcpy(dst, src2, 3);
//     printf("Test 3: %s\n", dst);

// 	return (0);
// }