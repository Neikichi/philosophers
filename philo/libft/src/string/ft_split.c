/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:51 by vlow              #+#    #+#             */
/*   Updated: 2024/12/15 16:42:44 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_split_ex(char const *s, char c, char **result);
static int	ft_countword(const char *str, char c);
static int	ft_insert(int i, char **result, int len);

/// @brief Split a string into words based on a given delimiter
/// 
/// This function splits the given string `s` into an array of strings
/// using the character `c` as a delimiter.
/// The resulting array of strings is null-terminated.
/// 
/// @param s The string to be split
/// @param c The character used as a delimiter
/// @return A pointer to an array of strings, or `NULL` if allocation fails
char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;	

	if (!s || *s == '\0')
	{
		result = malloc(sizeof(char *));
		if (!result)
			return (NULL);
		result[0] = NULL;
		return (result);
	}
	size = ft_countword(s, c);
	result = malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	return (ft_split_ex(s, c, result));
}

static char	**ft_split_ex(char const *s, char c, char **result)
{
	int			i;
	const char	*ptr;

	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			ptr = s;
			while (*ptr && (*ptr != c))
				ptr++;
			if (ft_insert(i, result, (ptr - s)))
				return (NULL);
			ft_strlcpy(result[i], s, (ptr - s + 1));
			i++;
			s = ptr;
		}
	}
	result[i] = NULL;
	return (result);
}

static int	ft_insert(int i, char **result, int len)
{
	result[i] = malloc(sizeof(char) * (len + 1));
	if (!result[i])
	{
		while (i > 0)
			free(result[--i]);
		free(result);
		return (1);
	}
	return (0);
}

static int	ft_countword(const char *str, char c)
{
	int	cnt;
	int	flag;
	int	set;

	cnt = 0;
	flag = 0;
	while (*str)
	{
		set = 0;
		if (*str == c)
			set = 1;
		if (set == 0 && flag == 0)
		{
			cnt++;
			flag = 1;
		}
		if (set == 1)
			flag = 0;
		str++;
	}
	return (cnt);
}

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*		char **result = ft_split("Hello,world,this,is,a,test", ',');*/
/*		if (result)*/
/*		{*/
/*				for (int i = 0; result[i] != NULL; i++)*/
/*				{*/
/*						printf("Word %d: %s\n", i, result[i]);*/
/*						free(result[i]);*/
/*				}*/
/*				free(result);*/
/*		}*/
/**/
/*		result = ft_split(",start,middle,end,", ',');*/
/*		if (result)*/
/*		{*/
/*				for (int i = 0; result[i] != NULL; i++)*/
/*				{*/
/*						printf("Word %d: %s\n", i, result[i]);*/
/*						free(result[i]);*/
/*				}*/
/*				free(result);*/
/*		}*/
/**/
/*		result = ft_split("", ',');*/
/*		if (result)*/
/*		{*/
/*				if (result[0] == NULL)*/
/*						printf("Empty string result: NULL\n");*/
/*				free(result);*/
/*		}*/
/**/
/*		return 0;*/
/*}*/
