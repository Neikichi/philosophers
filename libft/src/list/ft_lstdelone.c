/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:38:19 by vlow              #+#    #+#             */
/*   Updated: 2024/11/11 12:17:28 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief Delete a single element of the list
/// 
/// This function deletes and frees the given list
/// element `lst` using the function
/// `del` to free the content. The memory for the
/// list element itself is also freed.
/// 
/// @param lst A pointer to the list element to be deleted
/// @param del A pointer to a function used to
///				delete the content of the element

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*#include <stdio.h>*/
/*void ft_del(void *content)*/
/*{*/
/*		printf("Deleting content: %s\n", (char *)content);*/
/*		free(content);*/
/*}*/
/*int main(void)*/
/*{*/
/*		t_list node3 = {"node3", NULL};*/
/*		t_list node2 = {"node2", &node3};*/
/*		t_list node1 = {"node1", &node2};*/
/*		t_list *head = &node1;*/
/**/
/*		t_list *nodes = malloc(sizeof(t_list));*/
/*		char *ncont = ft_strdup("Hello");*/
/*		nodes->content = ncont;*/
/*		nodes->next = NULL;*/
/*		ft_lstadd_back(&head, nodes);*/
/**/
/**/
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
/*		ft_lstdelone(nodes, ft_del);*/
/*		node3.next = NULL;*/
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
