/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:21:52 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/15 16:16:30 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	cc;

	cc = (unsigned char)c;
	len = ft_strlen(s);
	if (cc == '\0')
		return ((char *)&s[len]);
	while (len > 0)
	{
		if (s[len - 1] == cc)
			return ((char *)&s[len - 1]);
		len--;
	}
	return (NULL);
}
// int main(void)
// {
// 	char str[] = "hello world";
// 	char c = 'l';
// 	char* result = ft_strrchr(str, c);

// 	printf("%s", result);
// }