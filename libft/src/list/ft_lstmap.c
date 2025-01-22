/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:38:49 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:38:52 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Create a new list by applying a function to 
///			each element of the original list
/// 
/// This function iterates through the list `lst`, applies the function
/// `f` to each element's content, and creates a new list with the
/// resulting elements. If an allocation fails, the `del` function
/// is called to delete the content, and the entire new list is cleared.
/// 
/// @param lst A pointer to the beginning of the list
/// @param f A function to apply to each element's content
/// @param del A function to delete the content in case of an allocation failure
/// @return A pointer to the newly created list, or NULL if an allocation fails
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	temp = lst;
	new = NULL;
	while (temp)
	{
		node = ft_lstnew(f(temp->content));
		if (!node)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		temp = temp->next;
	}
	return (new);
}

/*#include <stdlib.h>*/
/*#include <stdio.h>*/
/*void *ft_up(void *content)*/
/*{*/
/*	if (!content)*/
/*		return NULL;*/
/*	printf("Adding content: %s\n", (char *)content);*/
/*	char *dup = ft_strdup((char *)content);*/
/*	if (!dup)*/
/*		return NULL;*/
/*	char *ptr = dup;*/
/*	while (*ptr)*/
/*	{*/
/*		*ptr = (char)ft_toupper(*ptr);*/
/*		ptr++;*/
/*	}*/
/*	return ((void *)dup);*/
/*}*/
/*void ft_del(void *content)*/
/*{*/
/*		printf("Deleting content: %s\n", (char *)content);*/
/*		free(content);*/
/*}*/
/**/
/*int main(void)*/
/*{*/
/*		t_list *node3 = ft_lstnew(ft_strdup("node3"));*/
/*		t_list *node2 = ft_lstnew(ft_strdup("node2"));*/
/*		t_list *node1 = ft_lstnew(ft_strdup("node1"));*/
/*		t_list *head = ft_lstnew(ft_strdup("head"));*/
/**/
/*		t_list *nodes = ft_lstnew(ft_strdup("Hello"));*/
/*		ft_lstadd_back(&head, nodes);*/
/*		ft_lstadd_back(&head, node1);*/
/*		ft_lstadd_back(&head, node2);*/
/*		ft_lstadd_back(&head, node3);*/
/**/
/*		t_list *temp = head;*/
/*		printf("List before deletion:\n");*/
/*		while (temp)*/
/*		{*/
/*				printf("%s -> ", (char *)temp->content);*/
/*				temp = temp->next;*/
/*		}*/
/*		printf("NULL\n");*/
/**/
/*		t_list *newhead = ft_lstmap(nodes, ft_up, ft_del);*/
/*		if (!newhead)*/
/*		{*/
/*				ft_lstclear(&head, ft_del);*/
/*				return (1);*/
/*		}		*/
/*		temp = newhead;*/
/*		printf("\nList after deletion:\n");*/
/*		while (temp)*/
/*		{*/
/*				printf("%s -> ", (char *)temp->content);*/
/*				temp = temp->next;*/
/*		}*/
/*		printf("NULL\n");*/
/*		ft_lstclear(&head, ft_del);*/
/*		ft_lstclear(&newhead, ft_del);*/
/**/
/*		return 0;*/
/*}*/
/**/
/**/
/**/
/**/
/**/
