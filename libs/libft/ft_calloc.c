/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:09:26 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/15 13:28:30 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr_fresh;
	size_t	total;

	total = nmemb * size;
	ptr_fresh = malloc(total);
	if (!ptr_fresh)
		return (NULL);
	ft_bzero(ptr_fresh, total);
	return (ptr_fresh);
}
