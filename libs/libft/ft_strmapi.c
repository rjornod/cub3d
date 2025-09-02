/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:18:54 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/13 18:25:28 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh_str;
	int				slen;

	i = 0;
	slen = ft_strlen(s);
	fresh_str = (char *)malloc(sizeof(char) * slen + 1);
	if (!fresh_str)
		return (NULL);
	while (s[i])
	{
		fresh_str[i] = f(i, s[i]);
		i++;
	}
	fresh_str[i] = '\0';
	return (fresh_str);
}

// char    modify_char(unsigned int i, char c) {
// 	if (i % 2 == 0 && c >= 'a' && c <= 'z') {
// 		return c - ('a' - 'A');
// 	}
// 	return (c); 
// }

// int main() {
// 	char* str = "hello";
// 	char* result = ft_strmapi(str, &modify_char);

// 	if (result) {
// 		printf("%s\n", result);
// 		free(result);
// 	}
// 	return (0);
// }