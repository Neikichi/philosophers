/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:19 by vlow              #+#    #+#             */
/*   Updated: 2024/11/14 12:27:42 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/// @brief Copy memory area
/// 
/// This function copies `n` bytes from the memory area pointed to by `src` to
/// the memory area pointed to by `dest`. The memory areas should not overlap.
/// If they overlap, use `ft_memmove` instead.
/// 
/// @param dest A pointer to the destination memory area
/// @param src A pointer to the source memory area
/// @param n The number of bytes to be copied
/// @return A pointer to the destination memory area (`dest`)
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	i = 0;
	ptr_dest = dest;
	ptr_src = src;
	while (i < n)
	{
		*ptr_dest = *ptr_src;
		ptr_dest++;
		ptr_src++;
		i++;
	}
	return (dest);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*	char src[] = "Hello, world!";*/
/*	char dest[20];*/
/*	ft_memcpy(dest, src, strlen(src) + 1);*/
/*	printf("ft_memcpy result: %s\n", dest);*/
/**/
/*	int int_src[] = {1, 2, 3, 4, 5};*/
/*	int int_dest[5];*/
/*	ft_memcpy(int_dest, int_src, sizeof(int_src));*/
/*	printf("ft_memcpy result for integer array: ");*/
/*	for (size_t i = 0; i < 5; i++)*/
/*	{*/
/*		printf("%d ", int_dest[i]);*/
/*	}*/
/*	printf("\n");*/
/**/
/*	char std_dest[20];*/
/*	memcpy(std_dest, src, strlen(src) + 1);*/
/*	printf("Standard memcpy result: %s\n", std_dest);*/
/**/
/*	return 0;*/
/*}*/
