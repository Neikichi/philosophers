/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:35 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:39:37 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/// @brief Write a character to a file descriptor
/// 
/// This function writes the character `c` to the file descriptor `fd`.
/// 
/// @param c The character to be written
/// @param fd The file descriptor to write to (e.g., `1` for standard output)
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
