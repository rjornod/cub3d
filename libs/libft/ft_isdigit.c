/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanja <tanja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:06:03 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/11 13:15:18 by tanja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
// int main(void)
// {
//     printf("%i\n", ft_isdigit('9'));
//     printf("%i\n", ft_isdigit(9)); 
//     printf("%i\n", ft_isdigit('A'));
//     printf("%i\n", ft_isdigit('!'));
//     return (0);
// }