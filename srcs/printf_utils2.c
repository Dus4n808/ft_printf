/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:51:52 by dufama            #+#    #+#             */
/*   Updated: 2025/10/08 15:45:32 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(int nb)
{
	unsigned int	n;
	int				i;

	n = nb;
	i = 0;
	if (n <= 10)
		i += ft_putchar_printf(n + '0');
	else
	{
		i += ft_putnbr_unsigned(n / 10);
		i += ft_putnbr_unsigned(n % 10);
	}
	return (i);
}

int	ft_print_pointer(void *ptr)
{
	int	i;

	if (!ptr)
		return (write(1, "(nil)", 5));
	i = write(1, "0x", 2);
	i += ft_putnbr_hex((unsigned long)ptr);
	return (i);
}
