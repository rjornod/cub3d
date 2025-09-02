/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:45:51 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/15 13:06:30 by tignatov         ###   ########.fr       */
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

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*current;

// 	if (!new || !lst)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	current = *lst;
// 	while (current->next != NULL)
// 		current = current->next;
// 	current->next = new;
// }

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*current;

// 	if (!*lst || !lst)
// 		return ;
// 	current = *lst;
// 	while (*lst)
// 	{
// 		current = (*lst)->next;
// 		ft_lstdelone((*lst), del);
// 		*lst = current;
// 	}
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	if (!lst || !del)
// 		return ;
// 	del((lst)->content);
// 	free(lst);
// }

// void	*str_toupper(void *content)
// {
// 	char	*str = (char *)content;
// 	char	*new_str;

// 	if (!str)
// 		return NULL;
// 	new_str = ft_strdup(str);
// 	if (!new_str)
// 		return (NULL);
// 	for (int i = 0; new_str[i]; i++)
// 	{
// 		if (new_str[i] >= 'a' && new_str[i] <= 'z')
// 			new_str[i] -= 32;
// 	}
// 	return (new_str);
// }

// void del(void *content)
// {
// 	free(content);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// int main(void)
// {
// 	t_list *head;
// 	t_list *second;
// 	t_list *third;
// 	t_list *current;
// 	t_list *new_list;

// 	head = ft_lstnew(ft_strdup("hi"));
// 	second = ft_lstnew(ft_strdup("there"));
// 	third = ft_lstnew(ft_strdup("friend"));

// 	head->next = second;
// 	head->next->next = third;
// 	current = head;

// 	while(current)
// 	{
// 		printf("Before lst map: %s\n", (char *)current->content);
// 		current = current->next;
// 	}

// 	new_list = ft_lstmap(head, &str_toupper, del);
// 	current = new_list;
// 	while(current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	current = head;
// 	while(current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	ft_lstclear(&head, del);
// 	ft_lstclear(&new_list, del);
// }