/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:38:28 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:38:31 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Iterate through the list and apply a function to each element
/// 
/// This function iterates through the given linked list `lst` 
/// and applies the function
/// `f` to the content of each element.
/// 
/// @param lst A pointer to the beginning of the list
/// @param f A pointer to a function used to apply to each element's content
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/*void ft_del(void *content)*/
/*{*/
/*  printf("Adding content: %s\n", (char *)content);*/
/*  char *ptr = content;*/
/*  while (*ptr)*/
/*  {*/
/*    *ptr = ft_toupper(*ptr);*/
/*    ptr++;*/
/*  }*/
/*}*/
/*int main(void)*/
/*{*/
/*    t_list *node3 = ft_lstnew(ft_strdup("node3"));*/
/*    t_list *node2 = ft_lstnew(ft_strdup("node2"));*/
/*    t_list *node1 = ft_lstnew(ft_strdup("node1"));*/
/*    t_list *head = ft_lstnew(ft_strdup("head"));*/
/**/
/*    t_list *nodes = malloc(sizeof(t_list));*/
/*    char *ncont = ft_strdup("Hello");*/
/*    nodes->content = ncont;*/
/*    nodes->next = NULL;*/
/*    ft_lstadd_back(&head, nodes);*/
/*    ft_lstadd_back(&head, node1);*/
/*    ft_lstadd_back(&head, node2);*/
/*    ft_lstadd_back(&head, node3);*/
/**/
/*    t_list *temp = head;*/
/*    printf("List before deletion:\n");*/
/*    while (temp)*/
/*    {*/
/*        printf("%s -> ", (char *)temp->content);*/
/*        temp = temp->next;*/
/*    }*/
/*    printf("NULL\n");*/
/**/
/*    ft_lstiter(head, ft_del);*/
/**/
/*    temp = head;*/
/*    printf("\nList after deletion:\n");*/
/*    while (temp)*/
/*    {*/
/*        printf("%s -> ", (char *)temp->content);*/
/*        temp = temp->next;*/
/*    }*/
/*    printf("NULL\n");*/
/*    return 0;*/
/*}*/
/**/
/**/
/**/
/**/
