/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:37:58 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:38:00 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Add new element at the end of the list
/// 
/// This function adds a new element `new` at the end 
/// of the linked list pointed to by `lst`.
/// If the list is empty (i.e., `*lst` is NULL), 
/// the new element becomes the first element.
/// 
/// @param lst A double pointer to the beginning of the list
/// @param new A pointer to the new element to be added
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		if (temp)
		{
			temp->next = new;
		}
	}
}

/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/*int main(void)*/
/*{*/
/*		t_list node3 = {"node3", NULL};*/
/*		t_list node2 = {"node2", NULL};*/
/*		t_list node1 = {"node1", NULL};*/
/*		t_list *head = NULL;*/
/**/
/*		ft_lstadd_back(&head, &node1);*/
/*		ft_lstadd_back(&head, &node2);*/
/*		ft_lstadd_back(&head, &node3);*/
/**/
/*		t_list *temp = head;*/
/*		while (temp)*/
/*		{*/
/*				printf("%s -> ", (char*)temp->content);*/
/*				temp = temp->next;*/
/*		}*/
/*		printf("NULL\n");*/
/**/
/*		return 0;*/
/*}*/
/**/
/**/
