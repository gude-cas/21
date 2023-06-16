/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:22:33 by gude-cas          #+#    #+#             */
/*   Updated: 2023/04/26 18:04:21 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlnbr(long n, int *len)
{
	if (n < 0)
	{
		ft_putlchar('-', len);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putlnbr(n / 10, len);
		ft_putlnbr(n % 10, len);
	}
	else
		ft_putlchar(n + '0', len);
}
