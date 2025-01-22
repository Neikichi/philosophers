/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigits_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:33:36 by vlow              #+#    #+#             */
/*   Updated: 2024/11/28 16:34:25 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// For Hex base 16 Version.
/// Does not count sign symbols.
int	ft_countdigits_hex(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}
