/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:15:32 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/13 12:57:00 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		slen;
	char	*new_str;

	slen = ft_strlen(s1);
	new_str = (char *)malloc((slen + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, slen + 1);
	return (new_str);
}

// int main(void)
// {
// 	char original[] = "Hello, World!";
// 	char* duplicate = ft_strdup(original);
// 	printf("%s", duplicate);
// 	free(duplicate);
// }