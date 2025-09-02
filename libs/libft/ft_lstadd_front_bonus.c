/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:07:09 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/15 13:08:19 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft.h"

// t_list	*ft_lstnew(void const *content)
// {
// 	t_list	*new_list;

// 	new_list = (t_list *)malloc(sizeof(t_list));
// 	if (!new_list)
// 		return (NULL);
// 	new_list->content = (void *)content;
// 	new_list->next = NULL;
// 	return (new_list);
// }

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	new->next = *alst;
	*alst = new;
}

// int main(void)
// {
// 	t_list *head;
// 	t_list *new;
// 	t_list *current;
// 	t_list *temp;

// 	head = ft_lstnew("You");
// 	new = ft_lstnew("Hey");
// 	ft_lstadd_front(&head, new);
// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	current = head;
// 	while (current)
// 	{
// 		temp = current->next;
// 		free(current);
// 		current = temp;
// 	}
// }