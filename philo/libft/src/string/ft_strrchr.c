/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:40:40 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:40:43 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locate the last occurrence of a character in a string
/// 
/// This function searches for the last occurrence of the 
/// character `c` in the string `s`.
/// The terminating null byte is considered part of the string,
/// so if `c` is `\0`, the function returns a pointer to the 
/// null byte at the end of `s`.
/// 
/// @param s The string to be searched
/// @param c The character to be located (converted to `char`)
/// @return A pointer to the last occurrence of the character `c`
///			in the string or `NULL` if the character is not found
char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			ptr = (char *)s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (ptr);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*	const char *str1 = "Hello, \xE1world!";*/
/*	char *result1 = ft_strrchr(str1, 'd');*/
/*	printf("ft_strrchr result: %s\n", result1 ? result1 : "NULL");*/
/**/
/*	const char *str2 = "Hello, \xE1world!";*/
/*	char *std_result = strrchr(str2, 'd');*/
/*	printf("Standard strrchr result: %s\n", std_result ? std_result : "NULL");*/
/**/
/*	return 0;*/
/*}*/
