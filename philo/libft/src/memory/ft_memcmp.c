/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:14 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 23:07:32 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/// @brief Compare two memory blocks
/// 
/// Function compares the first `n` bytes of the memory areas `s1` and `s2`.
/// The comparison is done lexicographically as unsigned char values.
/// 
/// @param s1 A pointer to the first memory block
/// @param s2 A pointer to the second memory block
/// @param n The number of bytes to compare
/// @return An integer less than, equal to, or greater than zero if the first
///         differing byte in `s1` is found to be less than, to match, 
///         or be greater than the corresponding byte in `s2`
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptrs1;
	const unsigned char	*ptrs2;

	ptrs2 = (const unsigned char *)s2;
	ptrs1 = (const unsigned char *)s1;
	i = 0;
	while (i < n)
	{
		if (*ptrs1 != *ptrs2)
			return (*ptrs1 - *ptrs2);
		i++;
		ptrs1++;
		ptrs2++;
	}
	return (0);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*	char str1[] = "Hello, worl!";*/
/*	char str2[] = "Hello, world!";*/
/*	int result = ft_memcmp(str1, str2, strlen(str1));*/
/*	printf("ft_memcmp result for identical strings: %d\n", result);*/
/**/
/*	int std_result = memcmp(str1, str2, strlen(str1));*/
/*	printf("Standard memcmp result for different strings: %d\n", std_result);*/
/*	return 0;*/
/*}*/
