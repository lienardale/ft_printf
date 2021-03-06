/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <alienard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:51:47 by alienard          #+#    #+#             */
/*   Updated: 2019/12/03 13:58:41 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_s(t_bool *fl, int r)
{
	int		i;
	char	*tab;

	tab = (char *)fl->s;
	if (tab == NULL)
		tab = "(null)";
	i = 0;
	if (fl->preci == -1)
		r = ft_putstr_fd(tab, r);
	else if (fl->preci == 0 && fl->lpreci == 0)
		return (r);
	while (tab[i] && i < fl->lpreci)
	{
		r = ft_putchar_fd(tab[i], r);
		i++;
	}
	return (r);
}

int		ft_p(t_bool *fl, int r)
{
	r = ft_putchar_fd('0', r);
	r = ft_putchar_fd('x', r);
	if (fl->p != NULL || fl->lpad > 0 || fl->preci == -1
			|| (fl->preci == 0 && fl->lpreci != -1))
		r = ft_putnbr_hexa((long long unsigned int)fl->p, r);
	while (fl->p == NULL && fl->lpreci > 1)
	{
		r = ft_putchar_fd('0', r);
		(fl->lpreci)--;
	}
	return (r);
}

int		ft_c(t_bool *fl, char tab, int r)
{
	if (fl->fpad != '-')
	{
		r = ft_print_lpad(fl, r);
		r = ft_print_conv(fl, tab, r);
		return (r);
	}
	else
	{
		r = ft_print_conv(fl, tab, r);
		r = ft_print_lpad(fl, r);
		return (r);
	}
}

int		ft_len_preci(int len, t_bool *fl)
{
	if (fl->conv == 's' && fl->lpreci < len)
		len = fl->lpreci;
	if (fl->conv != 's' && fl->lpreci > len)
		len = fl->lpreci;
	if (ft_all_null(fl) == 1 && fl->lpreci == 0)
		len--;
	if (fl->neg == 2)
		len++;
	return (len);
}

int		ft_len_conv(int len, t_bool *fl)
{
	if (fl->conv == 'c')
		len = 1;
	else if (fl->conv == 's')
		len = (int)ft_strlen(fl->s);
	else if (fl->conv == 'p')
		len = ft_len_hexa((long long unsigned int)fl->p) + 3;
	else if (fl->conv == 'x')
		len = ft_len_hexa((long long unsigned int)fl->u) + 1;
	else if (fl->conv == 'X')
		len = ft_len_hexa((long long unsigned int)fl->u) + 1;
	else if (fl->conv == 'd')
		len = ft_len_d(fl->d) + 1;
	else if (fl->conv == 'u')
		len = ft_len_unsigned(fl->u) + 1;
	return (len);
}
