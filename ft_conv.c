/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:47:59 by alienard          #+#    #+#             */
/*   Updated: 2019/12/03 14:00:05 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_is_conv(char i)
{
	if (i == 'c' || i == 's' || i == 'p' || i == 'd' || i == 'i' || i == 'u'
			|| i == 'x' || i == 'X' || i == '%')
		return (1);
	return (0);
}

int		ft_all_null(t_bool *fl)
{
	if (fl->d == 0 && fl->u == 0
	&& (fl->conv == 'd' || fl->conv == 'u'
	|| fl->conv == 'x' || fl->conv == 'X'))
		return (1);
	return (0);
}

int		ft_conv_init(t_bool *fl, char tab, va_list ap, int r)
{
	(tab == 'c') ? (fl->c = va_arg(ap, int)) : 0;
	(tab == 's') ? (fl->s = va_arg(ap, char *)) : 0;
	(tab == 'p') ? (fl->p = va_arg(ap, void *)) : 0;
	(tab == 'd' || tab == 'i') ? (fl->d = va_arg(ap, int)) : 0;
	(tab == 'u') ? (fl->u = va_arg(ap, unsigned int)) : 0;
	(tab == 'x') ? (fl->u = va_arg(ap, unsigned int)) : 0;
	(tab == 'X') ? (fl->u = va_arg(ap, unsigned int)) : 0;
	if (ft_is_conv(tab) == 1)
	{
		(tab == 'c') ? (fl->conv = 'c') : 0;
		(tab == 's') ? (fl->conv = 's') : 0;
		(tab == 'p') ? (fl->conv = 'p') : 0;
		(tab == 'd' || tab == 'i') ? (fl->conv = 'd') : 0;
		(tab == 'u') ? (fl->conv = 'u') : 0;
		(tab == 'x') ? (fl->conv = 'x') : 0;
		(tab == 'X') ? (fl->conv = 'X') : 0;
	}
	if (fl->conv == 'd' && fl->d < 0)
		fl->neg = 0;
	r = ft_order(fl, tab, r);
	return (r);
}

int		ft_print_conv(t_bool *fl, char tab, int r)
{
	(tab == 'c') ? (r = ft_putchar_fd(fl->c, r)) : 0;
	(tab == 's') ? (r = ft_s(fl, r)) : 0;
	(tab == 'p') ? (r = ft_p(fl, r)) : 0;
	if (fl->lpreci == 0 && fl->preci == 0 && (ft_all_null(fl)) == 1)
		return (r);
	(tab == 'd' || tab == 'i') ? (r = ft_putnbr_fd(fl->d, r)) : 0;
	if (fl->d < 0 || fl->neg == 2)
		fl->neg = 1;
	(tab == 'u') ? (r = ft_putnbr_unsigned(fl->u, r)) : 0;
	(tab == 'x') ? (r = ft_putnbr_hexa(fl->u, r)) : 0;
	(tab == 'X') ? (r = ft_putnbr_hexm(fl->u, r)) : 0;
	return (r);
}
