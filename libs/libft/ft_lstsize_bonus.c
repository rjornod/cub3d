/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:09:08 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/14 17:16:44 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	t_list *list;
// 	int result;

// 	list = lstnew(strdup("1"));
// 	list->next = lstnew(strdup("2"));
// 	list->next->next = lstnew(strdup("3"));
// 	result = ft_lstsize(list);
// 	printf("%i", result);
// 	free(list);
// }