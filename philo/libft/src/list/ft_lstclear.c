/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:38:14 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:38:16 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Clear and delete all elements of the list
/// 
/// This function deletes and frees all elements of 
/// the linked list pointed to by `lst`,
/// using the function `del` to free the content of each element.
/// After freeing all elements, the list pointer is set to NULL.
/// 
/// @param lst A double pointer to the beginning of the list
/// @param del A pointer to a function used to delete
///				the content of each element
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/*void ft_del(void *content)*/
/*{*/
/*		printf("Deleting content: %s\n", (char *)content);*/
/*		free(content);*/
/*}*/
/*int main(void)*/
/*{*/
/*		t_list *node3 = ft_lstnew(ft_strdup("node3"));*/
/*		t_list *node2 = ft_lstnew(ft_strdup("node2"));*/
/*		t_list *node1 = ft_lstnew(ft_strdup("node1"));*/
/*		t_list *head = ft_lstnew(ft_strdup("head"));*/
/**/
/*		t_list *nodes = malloc(sizeof(t_list));*/
/*		char *ncont = ft_strdup("Hello");*/
/*		nodes->content = ncont;*/
/*		nodes->next = NULL;*/
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
/*		ft_lstclear(&head, ft_del);*/
/**/
/*		temp = head;*/
/*		printf("\nList after deletion:\n");*/
/*		while (temp)*/
/*		{*/
/*				printf("%s -> ", (char *)temp->content);*/
/*				temp = temp->next;*/
/*		}*/
/*		printf("NULL\n");*/
/*		return 0;*/
/*}*/
/**/
/**/
/**/
