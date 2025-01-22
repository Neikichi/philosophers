/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:45:13 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 15:10:55 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	fl_if_zero(t_flags *flags);
static void	fl_if_w(t_flags *flags, int *pvar);
static void	fl_if_la(t_flags *flags, int *pvar);

// pvar; 0 = n_len, 1 = p_len, 2 = n_size.
int	fl_sp_u(va_list vlist, t_flags *flags)
{
	unsigned int	val;
	int				pvar[3];

	val = va_arg(vlist, unsigned int);
	if (!val && !flags->precision)
		return (fl_if_zero(flags));
	pvar[1] = 0;
	pvar[0] = ft_countdigits_u(val);
	if (flags->precision > pvar[0])
		pvar[1] = flags->precision - pvar[0];
	flags->buffer = ft_itoa_u(val);
	if (!flags->buffer)
		return (0);
	pvar[2] = pvar[0] + pvar[1];
	fl_if_w(flags, pvar);
	free(flags->buffer);
	if (flags->width > pvar[2])
		return (flags->width);
	return (pvar[2]);
}

static void	fl_if_w(t_flags *flags, int *pvar)
{
	if (flags->width > pvar[2])
		fl_if_la(flags, pvar);
	else
	{
		if (pvar[1])
			ft_putnchar_fd('0', pvar[1], 1);
		ft_putstr_fd(flags->buffer, 1);
	}
}

static void	fl_if_la(t_flags *flags, int *pvar)
{
	if (flags->left_align)
	{
		if (pvar[1])
			ft_putnchar_fd('0', pvar[1], 1);
		ft_putstr_fd(flags->buffer, 1);
		ft_putnchar_fd(' ', flags->width - pvar[2], 1);
	}
	else
	{
		if (flags->precision >= 0 || !flags->zero_pad)
			ft_putnchar_fd(' ', flags->width - pvar[2], 1);
		if (pvar[1])
			ft_putnchar_fd('0', pvar[1], 1);
		else if (flags->zero_pad && flags->precision == -1)
			ft_putnchar_fd('0', flags->width - pvar[2], 1);
		ft_putstr_fd(flags->buffer, 1);
	}
}

static int	fl_if_zero(t_flags *flags)
{
	if (flags->width)
	{
		ft_putnchar_fd(' ', flags->width, 1);
		return (flags->width);
	}
	return (0);
}
