/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:38:44 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:38:46 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Get the last element of the list
/// 
/// This function returns the last element of the linked list `lst`.
/// If the list is empty (i.e., `lst` is NULL), the function returns NULL.
/// 
/// @param lst A pointer to the beginning of the list
/// @return A pointer to the last element of the list, or NULL if list is empty
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/*#include <stdio.h>*/
/*#include <stdlib.h>*/
/*int main(void)*/
/*{*/
/*		t_list node3 = {"node3", NULL};*/
/*		t_list node2 = {"node2", &node3};*/
/*		t_list head = {"head", &node2};*/
/**/
/*		t_list *last = ft_lstlast(&head);*/
/*		if (last)*/
/*		{*/
/*				printf("Last node content: %s\n", (char *)last->content);*/
/*		}*/
/**/
/*		return 0;*/
/*}*/
/**/
