/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:45:52 by vlow              #+#    #+#             */
/*   Updated: 2024/11/14 12:26:16 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief Allocate and zero-initialize an array
/// 
/// This function allocates memory for an array of 
/// `nmemb` elements of `size` bytes each,
/// and initializes all bytes to zero.
/// 
/// @param nmemb Number of elements to allocate
/// @param size Size of each element
/// @return Pointer to allocated memory, or NULL if allocation fails
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*init;
	size_t			i;

	if (nmemb == 0 || size == 0)
	{
		init = malloc(0);
		if (!init)
			return (NULL);
		return (init);
	}
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	i = nmemb * size;
	init = malloc(i);
	if (!init)
		return (NULL);
	ft_memset(init, 0, i);
	return (init);
}

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*	size_t nmemb = 3;*/
/*	char *arr = ft_calloc(nmemb, sizeof(char));*/
/**/
/*	if (!arr)*/
/*	{*/
/*		printf("Memory allocation failed.\n");*/
/*		return (1);*/
/*	}*/
/**/
/*	for (size_t i = 0; i < nmemb; i++)*/
/*	{*/
/*		printf("arr[%zu] = %d\n", i, arr[i]); */
/*	}*/
/**/
/*	free(arr);*/
/*	return 0;*/
/*}*/
