/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tignatov <tignatov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:45:58 by tignatov          #+#    #+#             */
/*   Updated: 2024/10/15 13:07:36 by tignatov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft.h"

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

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del((lst)->content);
	free(lst);
}

// void del(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
// 	t_list *temp;
// 	temp = ft_lstnew(ft_strdup("Wooo"));
// 	printf("%s\n", (char *)temp->content);
// 	ft_lstdelone(temp, del);
// }