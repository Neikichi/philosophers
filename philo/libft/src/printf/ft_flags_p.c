/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:42:06 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 15:10:01 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	fl_if_w(t_flags *flags, int *pvar);

// pvar: 0 = size, 1 = pfix
int	fl_sp_p(va_list vlist, t_flags *flags)
{
	void	*ptr;
	int		pvar[2];

	ptr = va_arg(vlist, void *);
	if (!ptr)
	{
		flags->buffer = ft_strdup("(nil)");
		pvar[1] = 0;
	}
	else
	{
		flags->buffer = ft_itoa_hex((unsigned long int)ptr);
		pvar[1] = 2;
	}
	if (!flags->buffer)
		return (0);
	pvar[0] = (int)ft_strlen(flags->buffer) + pvar[1];
	fl_if_w(flags, pvar);
	free(flags->buffer);
	if (flags->width > pvar[0])
		return (flags->width);
	return (pvar[0]);
}

static void	fl_if_w(t_flags *flags, int *pvar)
{
	if (flags->width > pvar[0])
	{
		pvar[0] = flags->width - pvar[0];
		if (flags->left_align)
		{
			if (pvar[1])
				ft_putstr_fd("0x", 1);
			ft_putstr_fd(flags->buffer, 1);
			ft_putnchar_fd(' ', pvar[0], 1);
		}
		else
		{
			ft_putnchar_fd(' ', pvar[0], 1);
			if (pvar[1])
				ft_putstr_fd("0x", 1);
			ft_putstr_fd(flags->buffer, 1);
		}
	}
	else
	{
		if (pvar[1])
			ft_putstr_fd("0x", 1);
		ft_putstr_fd(flags->buffer, 1);
	}
}
