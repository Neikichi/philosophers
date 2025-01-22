/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:35:51 by vlow              #+#    #+#             */
/*   Updated: 2024/11/09 22:35:58 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Check if character is alphanumeric
/// 
/// This function checks whether the given
/// character `c` is either a letter (alphabetic)
/// or a digit (0-9).
/// 
/// @param c The character to be checked
/// @return 1 if `c` is alphanumeric, 0 otherwise
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
