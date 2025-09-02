/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:06:19 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/14 17:16:17 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "libft.h"

static void	ft_itoa_helper(int n, char *arr, int *i)
{
	if (n > 9)
		ft_itoa_helper(n / 10, arr, i);
	arr[*i] = n % 10 + '0';
	(*i)++;
}

static int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*arr;
	int		len;

	i = 0;
	len = ft_num_len(n);
	arr = (char *)malloc(len * sizeof(char) + 1);
	if (arr == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(arr, "-2147483648", 12);
		return (arr);
	}
	if (n < 0)
	{
		arr[i++] = '-';
		n = -n;
	}
	ft_itoa_helper(n, arr, &i);
	arr[i] = '\0';
	return (arr);
}

// int main() {
//     int num = -1234;
//     char	*result = ft_itoa(num);
// 	char 	*res = ft_itoa(-2147483648LL);
//     if (result != NULL) {
//         printf("%s\n", result);
//         free(result);
//     }
// 	if (res != NULL) {
//         printf("%s\n", res);
//         free(result);
//     }
//     return 0;
// }