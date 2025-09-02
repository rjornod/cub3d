/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanja <tanja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:11:44 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/11 17:07:28 by tanja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (const unsigned char *)src;
	if (ptr_dst == ptr_src || len == 0)
		return (dst);
	if (ptr_dst < ptr_src)
	{
		while (len--)
			*ptr_dst++ = *ptr_src++;
	}
	else
	{
		ptr_dst += (len - 1);
		ptr_src += (len - 1);
		while (len--)
			*ptr_dst-- = *ptr_src--;
	}
	return (dst);
}

// int main(void) {
//     char dst3[] = "abcdefg";
//     char dst4[] = "abcdefg";  
//     ft_memmove(dst3 + 2, dst3, 4);
//     memmove(dst4 + 2, dst4, 4);
//     printf("Custom memmove: %s\n", dst3);
//     printf("Built-in memmove: %s\n", dst4);
// }