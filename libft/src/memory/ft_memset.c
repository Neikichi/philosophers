/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:28 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:39:33 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Fill memory with a constant byte
/// 
/// This function fills the first `n` bytes of the memory area
/// pointed to by `s`
/// with the constant byte `c`.
/// 
/// @param s A pointer to the memory area to be filled
/// @param c The byte value to be set, passed as an int but
/// treated as an unsigned char
/// @param n The number of bytes to be filled
/// @return A pointer to the memory area (`s`)
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		*ptr = (unsigned char)c;
		ptr++;
		i++;
	}
	return (s);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*	char str[20] = "Hello, world!";*/
/*	ft_memset(str, '*', 5);*/
/*	printf("ft_memset result: %s\n", str);*/
/**/
/*	int arr[5] = {1, 2, 3, 4, 5};*/
/*	ft_memset(arr, 0, sizeof(arr));*/
/*	printf("result for integer array: ");*/
/*	for (size_t i = 0; i < 5; i++)*/
/*	{*/
/*		printf("%d ", arr[i]);*/
/*	}*/
/*	printf("\n");*/
/**/
/*	char std_str[20] = "Hello, world!";*/
/*	memset(std_str, '*', 5);*/
/*	printf("Standard memset result: %s\n", std_str);*/
/**/
/*	return 0;*/
/*}*/
