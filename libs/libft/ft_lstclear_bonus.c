/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:49:56 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/15 13:08:05 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	if (!lst || !del)
// 		return ;
// 	del((lst)->content);
// 	free(lst);
// }

// void	del(void *content)
// {
// 	free(content);
// }

// char	*ft_strdup(const char *s1)
// {
// 	int		slen;
// 	char	*new_str;

// 	slen = ft_strlen(s1);
// 	new_str = (char *)malloc((slen + 1) * sizeof(char));
// 	if (!new_str)
// 		return (NULL);
// 	ft_strlcpy(new_str, s1, slen + 1);
// 	return (new_str);
// }

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	if (!*lst || !lst)
		return ;
	current = *lst;
	while (*lst)
	{
		current = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = current;
	}
}

// int main(void)
// {
// 	t_list *head;
// 	t_list *second;
// 	t_list *third;
// 	t_list *current;

// 	head = ft_lstnew(ft_strdup("Hi"));
// 	second = ft_lstnew(ft_strdup("what's"));
// 	third = ft_lstnew(ft_strdup("up"));

// 	head->next = second;
// 	head->next->next = third;
// 	current = head;
// 	while (current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	ft_lstclear(&head, del);
// 	if (head == NULL)
// 		printf("cleared");
// }