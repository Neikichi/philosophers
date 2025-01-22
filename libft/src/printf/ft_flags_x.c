/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:23:58 by vlow              #+#    #+#             */
/*   Updated: 2024/12/08 15:11:04 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

static int	fl_if_zero(t_flags *flags);
static void	fl_if_la(t_flags *flags, int *pvar);
static void	fl_if_nw(t_flags *flags, int *pvar, unsigned int val);
static void	fl_if_w(t_flags *flags, int *pvar, unsigned int val);

// 0 = n_len, 1 = p_len, 2 = n_size, 3 = pfix.
int	fl_sp_x(va_list vlist, t_flags *flags)
{
	unsigned int	val;
	int				pvar[4];

	val = va_arg(vlist, unsigned int);
	if (!val && !flags->precision)
		return (fl_if_zero(flags));
	pvar[0] = ft_countdigits_hex(val);
	pvar[1] = 0;
	pvar[3] = 0;
	if (flags->precision > pvar[0])
		pvar[1] = flags->precision - pvar[0];
	if (flags->hash_hex && val != 0)
		pvar[3] = 2;
	pvar[2] = pvar[0] + pvar[1] + pvar[3];
	flags->buffer = ft_itoa_hex(val);
	if (!flags->buffer)
		return (0);
	if (flags->specifier == 'X')
		ft_struppercase(flags->buffer);
	fl_if_w(flags, pvar, val);
	free(flags->buffer);
	if (flags->width > pvar[2])
		return (flags->width);
	return (pvar[2]);
}

static void	fl_if_w(t_flags *flags, int *pvar, unsigned int val)
{
	if (flags->width > pvar[2])
		fl_if_la(flags, pvar);
	else
		fl_if_nw(flags, pvar, val);
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

static void	fl_if_la(t_flags *flags, int *pvar)
{
	if (flags->left_align)
	{
		if (pvar[3] && flags->specifier == 'x')
			ft_putstr_fd("0x", 1);
		else if (pvar[3] && flags->specifier == 'X')
			ft_putstr_fd("0X", 1);
		if (pvar[1])
			ft_putnchar_fd('0', pvar[1], 1);
		ft_putstr_fd(flags->buffer, 1);
		ft_putnchar_fd(' ', flags->width - pvar[2], 1);
	}
	else
	{
		if (flags->precision >= 0 || !flags->zero_pad)
			ft_putnchar_fd(' ', flags->width - pvar[2], 1);
		if (pvar[3] && flags->specifier == 'x')
			ft_putstr_fd("0x", 1);
		else if (pvar[3] && flags->specifier == 'X')
			ft_putstr_fd("0X", 1);
		if (pvar[1])
			ft_putnchar_fd('0', pvar[1], 1);
		else if (flags->zero_pad && flags->precision == -1)
			ft_putnchar_fd('0', flags->width - pvar[2], 1);
		ft_putstr_fd(flags->buffer, 1);
	}
}

static void	fl_if_nw(t_flags *flags, int *pvar, unsigned int val)
{
	if (pvar[3] && val != 0 && flags->specifier == 'x')
		ft_putstr_fd("0x", 1);
	else if (pvar[3] && val != 0 && flags->specifier == 'X')
		ft_putstr_fd("0X", 1);
	if (pvar[1])
		ft_putnchar_fd('0', pvar[1], 1);
	ft_putstr_fd(flags->buffer, 1);
}
