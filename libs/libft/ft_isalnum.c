/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanja <tanja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:04:57 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/11 13:15:09 by tanja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

// int	ft_isalpha(int c)
// {
// 	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
// }
// int	ft_isdigit(int c)
// {
// 	return (c >= 48 && c <= 57);
// }
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
