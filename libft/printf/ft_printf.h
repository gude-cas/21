/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:49:32 by gude-cas          #+#    #+#             */
/*   Updated: 2023/04/27 15:03:27 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putlchar(char c, int *len);
void	ft_putlstr(char *str, int *len);
void	ft_putlnbr(long n, int *len);
void	ft_putlhex(unsigned int n, char *b, int *len);
void	ft_putladd(size_t c, int *len);

#endif
