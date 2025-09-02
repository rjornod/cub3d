/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:04:17 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/13 15:11:55 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char	*s)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	minus = 1;
	result = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-')
		minus = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != '\0' && ft_isdigit(s[i]))
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * minus);
}

// int main(void)
// {
//     // Test Case 1: Simple positive number
//     char *s1 = "12345";
//     printf("Test 1 - Expected: 12345, Got: %d\n", ft_atoi(s1));

//     // Test Case 2: Simple negative number
//     char *s2 = "-6789";
//     printf("Test 2 - Expected: -6789, Got: %d\n", ft_atoi(s2));

//     // Test Case 3: Number with leading whitespace
//     char *s3 = "   42";
//     printf("Test 3 - Expected: 42, Got: %d\n", ft_atoi(s3));

//     // Test Case 4: Number with leading whitespace and sign
//     char *s4 = "\t\n -56";
//     printf("Test 4 - Expected: -56, Got: %d\n", ft_atoi(s4));

//     // Test Case 5: No digits
//     char *s5 = "abc123";
//     printf("Test 5 - Expected: 0, Got: %d\n", ft_atoi(s5));
// }