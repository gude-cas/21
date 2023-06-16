/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putladd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:01:32 by gude-cas          #+#    #+#             */
/*   Updated: 2023/04/27 15:02:10 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putladd(size_t c, int *len)
{
	if (!c)
	{
		*len += write(1, "(nil)", 5);
		return ;
	}
	if (c < 16)
	{
		ft_putlstr("0x", len);
		ft_putlchar("0123456789abcdef"[c % 16], len);
	}
	else
	{
		ft_putladd(c / 16, len);
		ft_putlchar("0123456789abcdef"[c % 16], len);
	}
}
