/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:40:00 by vlow              #+#    #+#             */
/*   Updated: 2024/11/11 12:12:36 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/// @brief Duplicate a string
/// 
/// This function allocates sufficient memory for a copy of the string `s`,
/// copies the string, and returns a pointer to it. The memory for the new
/// string is obtained with `malloc` and should be freed by the caller.
/// 
/// @param s The source string to be duplicated
/// @return A pointer to the duplicated string, or
///			`NULL` if memory allocation fails
char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}

/*#include <stdio.h>*/
/*#include <string.h>*/
/**/
/*int main(void)*/
/*{*/
/*	const char *src = "Hello, world!";*/
/*	char *dup = ft_strdup(src);*/
/**/
/*	if (dup)*/
/*	{*/
/*		printf("ft_strdup result: %s\n", dup);*/
/*		free(dup);*/
/*	}*/
/*	else*/
/*	{*/
/*		printf("ft_strdup failed to allocate memory.\n");*/
/*	}*/
/**/
/*	char *std_dup = strdup(src);*/
/*	if (std_dup)*/
/*	{*/
/*		printf("strdup result: %s\n", std_dup);*/
/*		free(std_dup);*/
/*	}*/
/*	else*/
/*	{*/
/*		printf("strdup failed to allocate memory.\n");*/
/*	}*/
/**/
/*	return 0;*/
/*}*/
