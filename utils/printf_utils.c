/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:20:49 by dufama            #+#    #+#             */
/*   Updated: 2025/10/07 17:09:58 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_printf(char c)
{
	return(write(1, &c, 1));
}
int	ft_putstr_printf(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putnbr_printf(int nb)
{
	long	n;
	int	i;

	i = 0;
	n = nb;
	if (n < 0)
	{
		i = ft_putchar_printf('-');
		n = -n;
	}
	if (n <= 9)
		i = ft_putchar_printf(n + '0');
	else
	{
		i = ft_putnbr_printf(n / 10);
		i = ft_putnbr_printf(n % 10);
	}
	return (i);
}


