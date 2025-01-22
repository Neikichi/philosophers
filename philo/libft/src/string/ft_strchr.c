/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:56 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:39:57 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Locate character in string
/// 
/// This function searches for the first occurrence of the 
/// character `c` in the string `s`.
/// The terminating null byte is considered part of the string,
/// so if `c` is `\0`,
/// the function returns a pointer to the null byte at the end of `s`.
/// 
/// @param s The string to be searched
/// @param c The character to be located (converted to `char`)
/// @return A pointer to the first occurrence of the
///			character `c` in the string,
///         or `NULL` if the character is not found
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*	const char *str = "Hello, world!";*/
/*	char *result = ft_strchr(str, 'w');*/
/*	if (result)*/
/*		printf("Char found: %s at %ld\n", result, result - str);*/
/*	else*/
/*		printf("Char not found.\n");*/
/**/
/*	return 0;*/
/*}*/
