/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:07 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 23:08:17 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/// @brief Locate byte in block of memory
/// 
/// This function scans the initial `n` bytes of the memory area 
/// pointed to by `s` for the first
/// occurrence of the byte `c`. The function returns a pointer to the
/// matching byte or `NULL` if
/// the byte is not found within the specified range.
/// 
/// @param s A pointer to the memory area to be scanned
/// @param c The value to be located, passed as an int but
///			 treated as an unsigned char
/// @param n The number of bytes to be analyzed
/// @return A pointer to the matching byte, or `NULL` if not found
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		i++;
		ptr++;
	}
	return (NULL);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*	char str[] = "Hello, world!";*/
/**/
/*	char *result = ft_memchr(str, 'w', strlen(str));*/
/*	if (result)*/
/*		printf("Found character 'w' at position: %ld\n", result - str);*/
/*	else*/
/*		printf("Character 'w' not found.\n");*/
/**/
/*	char *std_result = memchr(str, 'w', strlen(str));*/
/*	if (std_result)*/
/*		printf("memchr found 'w' at position: %ld\n", std_result - str);*/
/*	else*/
/*		printf("Standard memchr: Character 'w' not found.\n");*/
/**/
/*	return 0;*/
/*}*/
