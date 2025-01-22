/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:40:09 by vlow              #+#    #+#             */
/*   Updated: 2024/11/10 16:33:48 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief Concatenate two strings into a new dynamically allocated string
/// 
/// This function concatenates the strings `s1` and `s2` into a new string.
/// The memory for the new string is allocated using `malloc` and should be
/// freed by the caller.
/// 
/// @param s1 The first string
/// @param s2 The second string
/// @return A pointer to the newly allocated string,
///			or `NULL` if allocation fails
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;

	if (!s1 || !s2)
		return (NULL);
	buffer = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s1, ft_strlen(s1) + 1);
	ft_strlcat(buffer, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (buffer);
}

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*		const char *s1 = "Hello, ";*/
/*		const char *s2 = "world!";*/
/*		char *result = ft_strjoin(s1, s2);*/
/*		if (result)*/
/*		{*/
/*				printf("ft_strjoin result: %s\n", result);*/
/*				free(result);*/
/*		}*/
/*		else*/
/*		{*/
/*				printf("ft_strjoin failed to allocate memory.\n");*/
/*		}*/
/**/
/*		return 0;*/
/*}*/
