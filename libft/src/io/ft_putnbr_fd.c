/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:39:44 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:39:45 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Outputs an integer to the given file descriptor.
/// Must be within MIN and MAX of INT.
/// @param n The integer to output.
/// @param fd The file descriptor to write to.
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

/*int main(void)*/
/*{*/
/*		ft_putnbr_fd(-2147483648, 1);*/
/*		ft_putchar_fd('\n', 1);*/
/**/
/*		ft_putnbr_fd(2147483647, 1);*/
/*		ft_putchar_fd('\n', 1);*/
/**/
/*		return 0;*/
/*}*/
