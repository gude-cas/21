/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:16:31 by gude-cas          #+#    #+#             */
/*   Updated: 2023/04/27 15:01:08 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlhex(unsigned int n, char *b, int *len)
{
	long int	nr;

	nr = n;
	if (nr / 16 == 0)
		ft_putlchar(b[nr % 16], len);
	else
	{
		ft_putlhex(nr / 16, b, len);
		ft_putlchar(b[nr % 16], len);
	}
}
