/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:47 by vlow              #+#    #+#             */
/*   Updated: 2024/11/10 16:39:26 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Write a string to a file descriptor
/// 
/// This function writes the string `s` to the file descriptor `fd`.
/// 
/// @param s The string to be written
/// @param fd The file descriptor to write to (e.g., `1` for standard output)
void	ft_putstr_fd(char *s, int fd)
{
	if (!s || !fd)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

/*int main(void)*/
/*{*/
/*		ft_putstr_fd("Hello, world!", 1);*/
/*		ft_putchar_fd('\n', 1);*/
/**/
/*		return 0;*/
/*}*/
