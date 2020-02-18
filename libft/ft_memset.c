/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alienard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:49:42 by alienard          #+#    #+#             */
/*   Updated: 2019/10/23 19:54:55 by alienard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ub;
	size_t	i;

	ub = (char*)b;
	i = 0;
	while (i < len)
	{
		ub[i] = (char)c;
		i++;
	}
	return (b);
}
